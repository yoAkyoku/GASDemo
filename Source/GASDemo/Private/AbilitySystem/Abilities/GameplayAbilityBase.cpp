// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/GameplayAbilityBase.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "Character/GASCharacterBase.h"
#include "Player/GASPlayerController.h"

UGameplayAbilityBase::UGameplayAbilityBase()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	NetSecurityPolicy = EGameplayAbilityNetSecurityPolicy::ClientOrServer;
	ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateYes;
}

UGASAbilitySystemComponent* UGameplayAbilityBase::GetGASAbilitySystemComponentFromActorInfo() const
{
	return CurrentActorInfo ? Cast<UGASAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent.Get()) : nullptr;
}

AGASPlayerController* UGameplayAbilityBase::GetGASPlayerControllerFromActorInfo() const
{
	return CurrentActorInfo ? Cast<AGASPlayerController>(CurrentActorInfo->PlayerController.Get()) : nullptr;
}

AController* UGameplayAbilityBase::GetControllerFromActorInfo() const
{
	if (CurrentActorInfo)
	{
		if (APlayerController* PC = CurrentActorInfo->PlayerController.Get())
			return PC;

		// Owner chain
		AActor* TestActor = CurrentActorInfo->OwnerActor.Get();
		while (TestActor)
		{
			if (AController* C = Cast<AController>(TestActor))
				return C;
			if (APawn* Pawn = Cast<APawn>(TestActor))
				return Pawn->GetController();
			TestActor = TestActor->GetOwner();
		}
	}

	return nullptr;
}

AGASCharacterBase* UGameplayAbilityBase::GetGASCharacterFromActorInfo() const
{
	return CurrentActorInfo ? Cast<AGASCharacterBase>(CurrentActorInfo->AvatarActor.Get()) : nullptr;
}

bool UGameplayAbilityBase::BatchRPCTryActivateAbilityByTag(FGameplayTag Tag, bool EndAbilityImmediately)
{
	if (UGASAbilitySystemComponent* ASC = GetGASAbilitySystemComponentFromActorInfo())
	{
		for(const FGameplayAbilitySpec& Spec : ASC->GetActivatableAbilities())
		{
			if (Spec.Ability && Spec.DynamicAbilityTags.HasTagExact(Tag))
			{
				ASC->BatchRPCTryActivateAbility(Spec.Handle, EndAbilityImmediately);
			}
		}
	}

	return false;
}
