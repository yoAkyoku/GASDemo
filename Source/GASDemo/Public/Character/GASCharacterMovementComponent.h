// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTagContainer.h"
#include "GASCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API UGASCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:

	UGASCharacterMovementComponent();

protected:

	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;

	float GetGroundDistance() const;

protected:

	FGameplayTag MovingTag;
	FGameplayTag InAirTag;

};
