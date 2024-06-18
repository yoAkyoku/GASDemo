// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbilityBase.generated.h"

class UGASAbilitySystemComponent;
class AGASPlayerController;
class AGASCharacterBase;

/**
 * 
 */
UCLASS()
class GASDEMO_API UGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UGameplayAbilityBase();

	UFUNCTION(BlueprintPure, Category = Ability)
		UGASAbilitySystemComponent* GetGASAbilitySystemComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = Ability)
		AGASPlayerController* GetGASPlayerControllerFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = Ability)
		AController* GetControllerFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = Ability)
		AGASCharacterBase* GetGASCharacterFromActorInfo() const;

	UFUNCTION(BlueprintCallable)
		bool BatchRPCTryActivateAbilityByTag(FGameplayTag Tag, bool EndAbilityImmediately);

};
