// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "RecoverPostureExecution.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API URecoverPostureExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:

	URecoverPostureExecution();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

};
