// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GASAbilitySystemComponent.h"

UGASAbilitySystemComponent::UGASAbilitySystemComponent()
{
	ClearAbilityInput();
}

void UGASAbilitySystemComponent::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (InputTag.IsValid())
	{
		for (const FGameplayAbilitySpec& Spec : ActivatableAbilities.Items)
		{
			if (Spec.Ability && Spec.DynamicAbilityTags.HasTagExact(InputTag))
			{
				InputPressedSpecHandles.AddUnique(Spec.Handle);
				InputHeldSpecHandles.AddUnique(Spec.Handle);
			}
		}
	}
}

void UGASAbilitySystemComponent::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (InputTag.IsValid())
	{
		for (const FGameplayAbilitySpec& Spec : ActivatableAbilities.Items)
		{
			if (Spec.Ability && Spec.DynamicAbilityTags.HasTagExact(InputTag))
			{
				InputReleasedSpecHandles.AddUnique(Spec.Handle);
				InputHeldSpecHandles.Remove(Spec.Handle);
			}
		}
	}
}

void UGASAbilitySystemComponent::ProcessAbilityInput(float DeltaTime, bool bGamePaused)
{
	// 需要激活的GA
	static TArray<FGameplayAbilitySpecHandle> AbilitiesToActivate;

	// 處理在本幀的輸入按住技能
	for (const FGameplayAbilitySpecHandle& Handle : InputHeldSpecHandles)
	{
		if (const FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Handle))
		{
			if (Spec->Ability && !Spec->IsActive())
			{
				AbilitiesToActivate.AddUnique(Handle);
			}
		}
	}

	// 處理在本幀的輸入按下技能
	for (const FGameplayAbilitySpecHandle& Handle : InputPressedSpecHandles)
	{
		if (FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Handle))
		{
			if (!Spec->Ability) continue;
			if (Spec->IsActive())
			{
				AbilitySpecInputPressed(*Spec);
			}
			else
			{
				AbilitiesToActivate.AddUnique(Handle);
			}
		}
	}

	// 激活所有來自按住的能力
	for (const FGameplayAbilitySpecHandle& Handle : AbilitiesToActivate)
	{
		// 使用BatchRPC
		FScopedServerAbilityRPCBatcher RPCBatcher(this, Handle);
		TryActivateAbility(Handle);
	}

	// 處理在本幀的輸入放開技能
	for (const FGameplayAbilitySpecHandle& Handle : InputReleasedSpecHandles)
	{
		if (FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Handle))
		{
			if (!Spec->Ability) continue;
			if (Spec->IsActive())
			{
				AbilitySpecInputReleased(*Spec);
			}
		}
	}

	// 清除
	AbilitiesToActivate.Reset();
	ClearAbilityInput();
}

void UGASAbilitySystemComponent::ClearAbilityInput()
{
	InputPressedSpecHandles.Reset();
	InputReleasedSpecHandles.Reset();
	InputHeldSpecHandles.Reset();
}

bool UGASAbilitySystemComponent::ShouldDoServerAbilityRPCBatch() const
{
	return true;
}

bool UGASAbilitySystemComponent::BatchRPCTryActivateAbility(const FGameplayAbilitySpecHandle& InAbilityHandle, bool EndAbilityImmediately)
{
	bool bActivated = false;

	if (InAbilityHandle.IsValid())
	{
		FScopedServerAbilityRPCBatcher RPCBatcher(this, InAbilityHandle);
		bActivated = TryActivateAbility(InAbilityHandle, true);

		// 是否在激活後就結束能力
		if (EndAbilityImmediately)
		{
			CancelAbilityHandle(InAbilityHandle);
		}
	}

	return bActivated;
}

void UGASAbilitySystemComponent::ReleaseInputAbilityByTag(const FGameplayTag& InputTag)
{
	AbilityInputTagReleased(InputTag);

	for (const FGameplayAbilitySpecHandle& Handle : InputReleasedSpecHandles)
	{
		if (FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Handle))
		{
			if (!Spec->Ability) continue;
			if (Spec->IsActive())
			{
				AbilitySpecInputReleased(*Spec);
			}
		}
	}
}

void UGASAbilitySystemComponent::AbilitySpecInputPressed(FGameplayAbilitySpec& Spec)
{
	Super::AbilitySpecInputPressed(Spec);

	//調用輸入的複製事件 (WaitInputPress的Ability Task才能正常使用)
	if (Spec.IsActive())
		InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputPressed, Spec.Handle, Spec.ActivationInfo.GetActivationPredictionKey());
}

void UGASAbilitySystemComponent::AbilitySpecInputReleased(FGameplayAbilitySpec& Spec)
{
	Super::AbilitySpecInputReleased(Spec);

	//調用輸入的複製事件 (WaitInputRelease的Ability Task才能正常使用)
	if (Spec.IsActive())
		InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputReleased, Spec.Handle, Spec.ActivationInfo.GetActivationPredictionKey());
}
