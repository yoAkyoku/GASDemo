// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Task/AsyncTaskCooldownChanged.h"

UAsyncTaskCooldownChanged* UAsyncTaskCooldownChanged::ListenForCooldownChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayTagContainer InCooldownTags, bool bUseServer)
{
	UAsyncTaskCooldownChanged* ListenForCooldownChange = NewObject<UAsyncTaskCooldownChanged>();
	ListenForCooldownChange->ASC = AbilitySystemComponent;
	ListenForCooldownChange->CooldownTags = InCooldownTags;
	ListenForCooldownChange->bUseServer = bUseServer;

	if (!AbilitySystemComponent && InCooldownTags.Num() < 1)
	{
		ListenForCooldownChange->EndTask();
		return nullptr;
	}

	AbilitySystemComponent->OnActiveGameplayEffectAddedDelegateToSelf.AddUObject(ListenForCooldownChange, &UAsyncTaskCooldownChanged::OnActiveGameplayEffect);

	TArray<FGameplayTag> CooldownTagArray;
	InCooldownTags.GetGameplayTagArray(CooldownTagArray);

	for (const FGameplayTag& CooldownTag : CooldownTagArray)
	{
		AbilitySystemComponent->RegisterGameplayTagEvent(CooldownTag, EGameplayTagEventType::NewOrRemoved).AddUObject(ListenForCooldownChange, &UAsyncTaskCooldownChanged::OnCooldownTagChanged);
	}

	return ListenForCooldownChange;
}

void UAsyncTaskCooldownChanged::EndTask()
{
	if (ASC)
	{
		ASC->OnActiveGameplayEffectAddedDelegateToSelf.RemoveAll(this);
		
		TArray<FGameplayTag> CooldownTagArray;
		CooldownTags.GetGameplayTagArray(CooldownTagArray);

		for (const FGameplayTag& CooldownTag : CooldownTagArray)
		{
			ASC->RegisterGameplayTagEvent(CooldownTag, EGameplayTagEventType::NewOrRemoved).RemoveAll(this);
		}
	}

	SetReadyToDestroy();
	MarkAsGarbage();
}

void UAsyncTaskCooldownChanged::OnActiveGameplayEffect(UAbilitySystemComponent* Target, const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer AssetTags;
	SpecApplied.GetAllAssetTags(AssetTags);

	FGameplayTagContainer GrantedTags;
	SpecApplied.GetAllGrantedTags(GrantedTags);

	TArray<FGameplayTag> CooldownTagArray;
	CooldownTags.GetGameplayTagArray(CooldownTagArray);

	for (const FGameplayTag& CooldownTag : CooldownTagArray)
	{
		if (AssetTags.HasTagExact(CooldownTag) || GrantedTags.HasTagExact(CooldownTag))
		{
			float TimeRemaining = 0.f;
			float Duration = 0.f;

			FGameplayTagContainer CooldownTagContainer(GrantedTags.GetByIndex(0));
			GetCooldownRemainingForTag(CooldownTagContainer, TimeRemaining, Duration);

			if (ASC->GetOwnerRole() == ROLE_Authority)
			{
				// Player is server
				OnCooldownBegin.Broadcast(CooldownTag, TimeRemaining, Duration);
			}
			else if (!bUseServer && SpecApplied.GetContext().GetAbilityInstance_NotReplicated())
			{
				// Client predicted cooldown
				OnCooldownBegin.Broadcast(CooldownTag, TimeRemaining, Duration);
			}
			else if (bUseServer && !SpecApplied.GetContext().GetAbilityInstance_NotReplicated())
			{
				// Client use server's predicted cooldown
				OnCooldownBegin.Broadcast(CooldownTag, TimeRemaining, Duration);
			}
			else if (bUseServer && SpecApplied.GetContext().GetAbilityInstance_NotReplicated())
			{
				// Client use server's predicted cooldown
				OnCooldownBegin.Broadcast(CooldownTag, -1.f, -1.f);
			}
		}
	}
}

void UAsyncTaskCooldownChanged::OnCooldownTagChanged(const FGameplayTag CooldownTag, int32 NewCount)
{
	if(NewCount == 0)
		OnCooldownBegin.Broadcast(CooldownTag, -1.f, -1.f);
}

bool UAsyncTaskCooldownChanged::GetCooldownRemainingForTag(FGameplayTagContainer InCooldownTags, float& TimeRemaining, float& Duration)
{
	if (ASC && CooldownTags.Num() > 0)
	{
		const FGameplayEffectQuery Query = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(InCooldownTags);
		TArray<TPair<float, float>> TimeRemainingAndDuration = ASC->GetActiveEffectsTimeRemainingAndDuration(Query);

		if (TimeRemainingAndDuration.Num() > 0)
		{
			int32 BestIdx = 0;
			float LongestTime = TimeRemainingAndDuration[0].Key;

			for (int32 Idx = 1; Idx < TimeRemainingAndDuration.Num(); ++Idx)
			{
				if (TimeRemainingAndDuration[Idx].Key > LongestTime)
				{
					LongestTime = TimeRemainingAndDuration[Idx].Key;
					BestIdx = Idx;
				}
			}

			TimeRemaining = TimeRemainingAndDuration[BestIdx].Key;
			Duration = TimeRemainingAndDuration[BestIdx].Value;

			return true;
		}
	}

	return false;
}
