// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/GASGameModeBase.h"
#include "Character/GASCharacterBase.h"
#include "Player/GASPlayerController.h"
#include "Player/GASPlayerState.h"

AGASGameModeBase::AGASGameModeBase()
{
	DefaultPawnClass = AGASCharacterBase::StaticClass();
	PlayerControllerClass = AGASPlayerController::StaticClass();
	PlayerStateClass = AGASPlayerState::StaticClass();
}
