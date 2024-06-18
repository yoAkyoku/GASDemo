// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GASPlayerState.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"

AGASPlayerState::AGASPlayerState()
{
	// Create ASC
	ASC = CreateDefaultSubobject<UGASAbilitySystemComponent>(TEXT("ASC"));
	ASC->SetIsReplicated(true);
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// ������s�W�v (�i�H�ھڻݨD�վ�)
	NetUpdateFrequency = 100.f;

}

UAbilitySystemComponent* AGASPlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}
