// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GASPlayerController.h"
#include "Player/GASPlayerState.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "Widget/MainWidget.h"

AGASPlayerState* AGASPlayerController::GetGASPlayerState() const
{
	return PlayerState ? Cast<AGASPlayerState>(PlayerState) : nullptr;
}

UGASAbilitySystemComponent* AGASPlayerController::GetGASAbilitySystemComponent() const
{
	AGASPlayerState* PS = GetGASPlayerState();
	return PS ? PS->GetGASAbilitySystemComponent() : nullptr;
}

void AGASPlayerController::PostProcessInput(const float DeltaTime, const bool bGamePaused)
{
	if (UGASAbilitySystemComponent* ASC = GetGASAbilitySystemComponent())
	{
		ASC->ProcessAbilityInput(DeltaTime, bGamePaused);
	}

	Super::PostProcessInput(DeltaTime, bGamePaused);
}
