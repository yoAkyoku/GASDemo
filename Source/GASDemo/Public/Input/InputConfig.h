// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "InputConfig.generated.h"

USTRUCT(BlueprintType)
struct FTaggedInputAction
{
	GENERATED_BODY();

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
		const class UInputAction* InputAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
		FGameplayTag InputTag;
};

/**
 * 
 */
UCLASS()
class GASDEMO_API UInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	UFUNCTION()
	const UInputAction* FindInputActionByTag(const FGameplayTag& InputTag) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<FTaggedInputAction> NativeInputActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<FTaggedInputAction> AbilityInputActions;

};
