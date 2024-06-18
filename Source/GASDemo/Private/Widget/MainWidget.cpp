// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/MainWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Character/GASCharacterBase.h"
#include "AbilitySystem/AttributeSets/GASCharacterAttributeSet.h"
#include "Components/Border.h"

void UMainWidget::NativeConstruct()
{
	if (AGASCharacterBase* Character = Cast<AGASCharacterBase>(GetOwningPlayerPawn()))
	{
		if (const UGASCharacterAttributeSet* Set = Character->AttributeSet)
		{
			SetHealth(Set->GetHealth());
			SetMaxHealth(Set->GetMaxHealth());
			SetPosture(Set->GetPosture());
			SetMaxPosture(Set->GetMaxPosture());
			SetStamina(Set->GetStamina());
			SetMaxStamina(Set->GetMaxStamina());
		}
	}

}

void UMainWidget::ShowBossStatus(bool bShow)
{
	BossStatus->SetVisibility(bShow ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void UMainWidget::SetHealth(float Value)
{
	Health = Value;
}

void UMainWidget::SetMaxHealth(float Value)
{
	MaxHealth = Value;
}

void UMainWidget::SetPosture(float Value)
{
	Posture = Value;
}

void UMainWidget::SetMaxPosture(float Value)
{
	MaxPosture = Value;
}

void UMainWidget::SetStamina(float Value)
{
	Stamina = Value;
}

void UMainWidget::SetMaxStamina(float Value)
{
	MaxStamina = Value;
}

void UMainWidget::SetBossHealth(float Value)
{
	BossHealth = Value;
}

void UMainWidget::SetMaxBossHealth(float Value)
{
	MaxBossHealth = Value;
}

void UMainWidget::SetBossPosture(float Value)
{
	BossPosture = Value;
}

void UMainWidget::SetMaxBossPosture(float Value)
{
	MaxBossPosture = Value;
}