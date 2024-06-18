// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASCharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 *	角色屬性集
 */
UCLASS()
class GASDEMO_API UGASCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UGASCharacterAttributeSet();

	//	角色的各項屬性
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = Attribute)
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = Attribute)
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = Attribute)
		FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = Attribute)
		FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, MaxStamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Posture, Category = Attribute)
		FGameplayAttributeData Posture;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, Posture);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxPosture, Category = Attribute)
		FGameplayAttributeData MaxPosture;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, MaxPosture);

	UPROPERTY(BlueprintReadOnly, Category = Attribute)
		FGameplayAttributeData PostureRegenRate;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, PostureRegenRate);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MoveSpeedRate, Category = Attribute)
		FGameplayAttributeData MoveSpeedRate;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, MoveSpeedRate);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMoveSpeedRate, Category = Attribute)
		FGameplayAttributeData MaxMoveSpeedRate;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, MaxMoveSpeedRate);

	//	Meta attribute (僅計算傷害時臨時使用)
	UPROPERTY(BlueprintReadOnly, Category = Attribute)
		FGameplayAttributeData BaseDamage;
	ATTRIBUTE_ACCESSORS(UGASCharacterAttributeSet, BaseDamage);


protected:

	UFUNCTION()
		void OnRep_Health(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
		void OnRep_Stamina(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MaxStamina(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_Posture(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MaxPosture(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MoveSpeedRate(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MaxMoveSpeedRate(const FGameplayAttributeData& OldValue);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	void ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const;

};
