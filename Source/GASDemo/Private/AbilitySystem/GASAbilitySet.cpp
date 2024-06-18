// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GASAbilitySet.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayEffect.h"
#include "AttributeSet.h"

void FGASAbilitySet_GrantedHandles::AddAbilitySpecHandle(const FGameplayAbilitySpecHandle& Handle)
{
	if (Handle.IsValid())
		AbilitySpecHandles.Add(Handle);
}


void FGASAbilitySet_GrantedHandles::AddEffectSpecHandle(const FActiveGameplayEffectHandle& Handle)
{
	if (Handle.IsValid())
		EffectSpecHandles.Add(Handle);
}

void FGASAbilitySet_GrantedHandles::AddAttributeSet(UAttributeSet* Set)
{
	if (Set)
		AttributeSets.Add(Set);
}

void FGASAbilitySet_GrantedHandles::ClearHandlesFromASC(UAbilitySystemComponent* ASC)
{
	if (!ASC && !ASC->IsOwnerActorAuthoritative()) return;

	for (const FGameplayAbilitySpecHandle& Handle : AbilitySpecHandles)
	{
		if (Handle.IsValid())
		{
			ASC->ClearAbility(Handle);
		}
	}

	for (const FActiveGameplayEffectHandle& Handle : EffectSpecHandles)
	{
		if (Handle.IsValid())
		{
			ASC->RemoveActiveGameplayEffect(Handle);
		}
	}

	for (UAttributeSet* Set : AttributeSets)
	{
		if (Set)
		{
			ASC->RemoveSpawnedAttribute(Set);
		}
	}

	AbilitySpecHandles.Reset();
	EffectSpecHandles.Reset();
	AttributeSets.Reset();
}

FGASAbilitySet_GrantedHandles UGASAbilitySet::GiveToAbilitySystem(UAbilitySystemComponent* ASC)
{
	FGASAbilitySet_GrantedHandles OutGrantedHandles;

	if (ASC && ASC->IsOwnerActorAuthoritative())
	{
		for (const FGASAbilitySet_GameplayAbility& GrantedAbility : GrantedAbilities)
		{
			UGameplayAbility* GA = GrantedAbility.Ability->GetDefaultObject<UGameplayAbility>();
			FGameplayAbilitySpec AbilitySpec(GA, GrantedAbility.Level);
			AbilitySpec.DynamicAbilityTags.AddTag(GrantedAbility.AbilityTag);
			const FGameplayAbilitySpecHandle AbilitySpecHandle = ASC->GiveAbility(AbilitySpec);

			OutGrantedHandles.AddAbilitySpecHandle(AbilitySpecHandle);
		}

		for (const FGASAbilitySet_GameplayEffect& GrantedEffect : GrantedEffects)
		{
			const UGameplayEffect* GE = GrantedEffect.Effect->GetDefaultObject<UGameplayEffect>();
			const FActiveGameplayEffectHandle EffectHandle = ASC->ApplyGameplayEffectToSelf(GE, GrantedEffect.Level, ASC->MakeEffectContext());

			OutGrantedHandles.AddEffectSpecHandle(EffectHandle);
		}

		for (const FGASAbilitySet_AttributeSet& GrantedAttributeSet : GrantedAttributeSets)
		{
			UAttributeSet* NewSet = NewObject<UAttributeSet>(ASC->GetOuter(), GrantedAttributeSet.AttributeSet);
			ASC->AddAttributeSetSubobject(NewSet);

			OutGrantedHandles.AddAttributeSet(NewSet);
		}
	}

	return OutGrantedHandles;
}

TSubclassOf<UGameplayAbility> UGASAbilitySet::FindGrantedAbilityByTagName(FName TagName) const
{
	for (const FGASAbilitySet_GameplayAbility& GrantedAbility : GrantedAbilities)
	{
		if (GrantedAbility.AbilityTag == FGameplayTag::RequestGameplayTag(TagName, false))
			return GrantedAbility.Ability;
	}

	return nullptr;
}
