// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Execution/DamageExecution.h"
#include "AbilitySystem/AttributeSets/GASCharacterAttributeSet.h"

struct FDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(BaseDamage);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Posture);

	FDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASCharacterAttributeSet, BaseDamage, Source, true);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASCharacterAttributeSet, Posture, Target, false);
	}
};

static FDamageStatics& DamageStatics()
{
	static FDamageStatics Statics;
	return Statics;
}

UDamageExecution::UDamageExecution()
{
	RelevantAttributesToCapture.Add(DamageStatics().BaseDamageDef);
	RelevantAttributesToCapture.Add(DamageStatics().PostureDef);
}

void UDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
	UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
				
	FAggregatorEvaluateParameters EvaluateParams;
	EvaluateParams.SourceTags = SourceTags;
	EvaluateParams.TargetTags = TargetTags;

	float Damage = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().BaseDamageDef, EvaluateParams, Damage);

	float Posture = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().PostureDef, EvaluateParams, Posture);

	float ReductionPosture = 0.f;

	// 該攻擊是否可防禦
	if (SourceASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Ability.State.CanDefense")) && Posture > 0.f)
	{
		// Target有防禦，但不是完美防禦
		if(TargetASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Character.Movement.Defense")) &&
			!(TargetASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Character.Status.Buff.DefensePerfect"))))
		{
			Damage = 0.f;
			ReductionPosture = 5.f;
		}

		// 交鋒
		if (TargetASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Ability.State.Attack.Hit")))
		{
			Damage = 0.f;
			ReductionPosture = 1.f;
		}
	}

	if (Damage < 0.f)
		Damage = 0.f;

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().BaseDamageProperty, EGameplayModOp::Additive, Damage));

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().PostureProperty, EGameplayModOp::Additive, -ReductionPosture));

}
