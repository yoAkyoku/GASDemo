// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Execution/RecoverPostureExecution.h"
#include "AbilitySystem/AttributeSets/GASCharacterAttributeSet.h"

struct FPostureStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(PostureRegenRate);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(MaxHealth);

	FPostureStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASCharacterAttributeSet, PostureRegenRate, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASCharacterAttributeSet, Health, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASCharacterAttributeSet, MaxHealth, Source, false);
	}
};

static FPostureStatics& PostureStatics()
{
	static FPostureStatics Statics;
	return Statics;
}

URecoverPostureExecution::URecoverPostureExecution()
{
	RelevantAttributesToCapture.Add(PostureStatics().PostureRegenRateDef);
	RelevantAttributesToCapture.Add(PostureStatics().HealthDef);
	RelevantAttributesToCapture.Add(PostureStatics().MaxHealthDef);
}

void URecoverPostureExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParams;
	EvaluateParams.SourceTags = SourceTags;
	EvaluateParams.TargetTags = TargetTags;

	float PostureRegenRate = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(PostureStatics().PostureRegenRateDef, EvaluateParams, PostureRegenRate);

	float Health = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(PostureStatics().HealthDef, EvaluateParams, Health);

	float MaxHealth = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(PostureStatics().MaxHealthDef, EvaluateParams, MaxHealth);

	// 體幹恢復值會根據血量而改變 (100%、75%、50%、25%)
	if ((Health / MaxHealth) <= .75f)
		PostureRegenRate *= .75f;
	else if ((Health / MaxHealth) <= .5f)
		PostureRegenRate *= .5f;
	else if ((Health / MaxHealth) <= .25f)
		PostureRegenRate *= .25f;

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(PostureStatics().PostureRegenRateProperty, EGameplayModOp::Override, PostureRegenRate));
}
