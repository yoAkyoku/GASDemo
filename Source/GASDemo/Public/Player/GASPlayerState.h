// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "GASPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API AGASPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:

	AGASPlayerState();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ability)
		class UGASAbilitySystemComponent* ASC;

public:

	UFUNCTION(BlueprintCallable)
		UGASAbilitySystemComponent* GetGASAbilitySystemComponent() const { return ASC; }

	// Implement AbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
