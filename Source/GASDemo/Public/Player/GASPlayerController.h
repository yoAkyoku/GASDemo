// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GASPlayerController.generated.h"

class AGASPlayerState;
class UGASAbilitySystemComponent;
class UMainWidget;

/**
 * 
 */
UCLASS()
class GASDEMO_API AGASPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = PlayerController)
		AGASPlayerState* GetGASPlayerState() const;

	UFUNCTION(BlueprintCallable, Category = PlayerController)
		UGASAbilitySystemComponent* GetGASAbilitySystemComponent() const;

	UPROPERTY(BlueprintReadWrite, Category = UI)
		UMainWidget* HUDWidget;
	
	// �b�o�B�z��J��O
	virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;

};
