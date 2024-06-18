// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayEffect.h"
#include "AttributeSet.h"
#include "GASAbilitySet.generated.h"

USTRUCT(BlueprintType)
struct FGASAbilitySet_GameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UGameplayAbility> Ability = nullptr;

	UPROPERTY(EditDefaultsOnly)
		int32 Level = 1;

	UPROPERTY(EditDefaultsOnly)
		FGameplayTag AbilityTag;
};

USTRUCT(BlueprintType)
struct FGASAbilitySet_GameplayEffect
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UGameplayEffect> Effect = nullptr;

	UPROPERTY(EditDefaultsOnly)
		int32 Level = 1;
};

USTRUCT(BlueprintType)
struct FGASAbilitySet_AttributeSet
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UAttributeSet> AttributeSet = nullptr;
};

USTRUCT(BlueprintType)
struct FGASAbilitySet_GrantedHandles
{
	GENERATED_BODY()

public:

	void AddAbilitySpecHandle(const FGameplayAbilitySpecHandle& Handle);
	void AddEffectSpecHandle(const FActiveGameplayEffectHandle& Handle);
	void AddAttributeSet(UAttributeSet* Set);

	// �R���Ҧ��ᤩ�����e (�Ҧp��W�R���Z����������O)
	void ClearHandlesFromASC(UAbilitySystemComponent* ASC);

protected:

	UPROPERTY()
		TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;
	UPROPERTY()
		TArray<FActiveGameplayEffectHandle> EffectSpecHandles;
	UPROPERTY()
		TArray<TObjectPtr<UAttributeSet>> AttributeSets;
};


/**
 *	GA�BGE�BAS�겣��
 */
UCLASS()
class GASDEMO_API UGASAbilitySet : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	//�NAbilitySet�ᤩ��ASC
	FGASAbilitySet_GrantedHandles GiveToAbilitySystem(UAbilitySystemComponent* ASC);

	//�qAbilitySet�����w�ᤩ��GA
	UFUNCTION(BlueprintCallable)
		TSubclassOf<UGameplayAbility> FindGrantedAbilityByTagName(FName TagName) const;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
		TArray<FGASAbilitySet_GameplayAbility> GrantedAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		TArray<FGASAbilitySet_GameplayEffect> GrantedEffects;

	UPROPERTY(EditDefaultsOnly, Category = "AttributeSets")
		TArray<FGASAbilitySet_AttributeSet> GrantedAttributeSets;
	
};
