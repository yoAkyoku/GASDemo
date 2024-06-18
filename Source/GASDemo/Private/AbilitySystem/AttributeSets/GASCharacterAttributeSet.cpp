// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AttributeSets/GASCharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

UGASCharacterAttributeSet::UGASCharacterAttributeSet()
	:Health(100.f),
	 MaxHealth(100.f),
	 Stamina(100.f),
	 MaxStamina(100.f),
	 Posture(100.f),
	 MaxPosture(100.f),
	 MoveSpeedRate(1.f),
	 MaxMoveSpeedRate(2.f)
{

}

void UGASCharacterAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASCharacterAttributeSet, Health, OldValue);
}

void UGASCharacterAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASCharacterAttributeSet, MaxHealth, OldValue);
}

void UGASCharacterAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASCharacterAttributeSet, Stamina, OldValue);
}

void UGASCharacterAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASCharacterAttributeSet, MaxStamina, OldValue);
}

void UGASCharacterAttributeSet::OnRep_Posture(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASCharacterAttributeSet, Posture, OldValue);
}

void UGASCharacterAttributeSet::OnRep_MaxPosture(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASCharacterAttributeSet, MaxPosture, OldValue);
}

void UGASCharacterAttributeSet::OnRep_MoveSpeedRate(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASCharacterAttributeSet, MoveSpeedRate, OldValue);
}

void UGASCharacterAttributeSet::OnRep_MaxMoveSpeedRate(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASCharacterAttributeSet, MaxMoveSpeedRate, OldValue);
}

void UGASCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASCharacterAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASCharacterAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASCharacterAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASCharacterAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASCharacterAttributeSet, Posture, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASCharacterAttributeSet, MaxPosture, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASCharacterAttributeSet, MoveSpeedRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASCharacterAttributeSet, MaxMoveSpeedRate, COND_None, REPNOTIFY_Always);
}

void UGASCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	// GE修改屬性是BaseDamage時，應用傷害
	if (Data.EvaluatedData.Attribute == GetBaseDamageAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth() - GetBaseDamage(), 0.f, GetMaxHealth()));
		SetBaseDamage(0.f);
	}
	else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == GetPostureRegenRateAttribute())
	{
		SetPosture(FMath::Clamp(GetPosture() + GetPostureRegenRate(), 0.f, GetMaxPosture()));
		SetPostureRegenRate(0.f);
	}

	// 也可以在這做其他處理
	// 例如這次造成傷害擊殺敵人，GE的來源獲取經驗等獎勵
	// 可參考GASShooter (https://github.com/tranek/GASShooter)
}

void UGASCharacterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	ClampAttribute(Attribute, NewValue);
}

void UGASCharacterAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	ClampAttribute(Attribute, NewValue);
}

void UGASCharacterAttributeSet::ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetMaxHealthAttribute())
	{
		//屬性最大值不可小於1
		NewValue = FMath::Max(NewValue, 1.f);
	}
	else if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
	}
	else if (Attribute == GetMaxStaminaAttribute())
	{
		//屬性最大值不可小於1
		NewValue = FMath::Max(NewValue, 1.f);
	}
	else if (Attribute == GetPostureAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxPosture());
	}
	else if (Attribute == GetMaxPostureAttribute())
	{
		//屬性最大值不可小於1
		NewValue = FMath::Max(NewValue, 1.f);
	}
	else if (Attribute == GetMoveSpeedRateAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMoveSpeedRate());
	}
	else if (Attribute == GetMaxMoveSpeedRateAttribute())
	{
		//屬性最大值不可小於1
		NewValue = FMath::Max(NewValue, 1.f);
	}
}
