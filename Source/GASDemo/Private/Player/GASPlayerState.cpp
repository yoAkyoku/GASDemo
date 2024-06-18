// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GASPlayerState.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"

AGASPlayerState::AGASPlayerState()
{
	// Create ASC
	ASC = CreateDefaultSubobject<UGASAbilitySystemComponent>(TEXT("ASC"));
	ASC->SetIsReplicated(true);
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// 網路更新頻率 (可以根據需求調整)
	NetUpdateFrequency = 100.f;

}

UAbilitySystemComponent* AGASPlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}
