// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

class UProgressBar;
class UTextBlock;
class UBorder;

/**
 * 
 */
UCLASS()
class GASDEMO_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* TXT_Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UProgressBar* PostureBar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* TXT_Posture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UProgressBar* StaminaBar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* TXT_Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UBorder* BossStatus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UProgressBar* BossHealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* TXT_BossHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UProgressBar* BossPostureBar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
		UTextBlock* TXT_BossPosture;

	UPROPERTY(BlueprintReadWrite)
	float Health;

	UPROPERTY(BlueprintReadWrite)
		float MaxHealth;

	UPROPERTY(BlueprintReadWrite)
		float Posture;

	UPROPERTY(BlueprintReadWrite)
		float MaxPosture;

	UPROPERTY(BlueprintReadWrite)
		float Stamina;

	UPROPERTY(BlueprintReadWrite)
		float MaxStamina;

	UPROPERTY(BlueprintReadWrite)
		float BossHealth;

	UPROPERTY(BlueprintReadWrite)
		float MaxBossHealth;

	UPROPERTY(BlueprintReadWrite)
		float BossPosture;

	UPROPERTY(BlueprintReadWrite)
		float MaxBossPosture;

protected:

	virtual void NativeConstruct() override;

public:

	void ShowBossStatus(bool bShow);

	UFUNCTION(BlueprintCallable)
		void SetHealth(float Value);

	UFUNCTION(BlueprintCallable)
		void SetMaxHealth(float Value);

	UFUNCTION(BlueprintCallable)
		void SetPosture(float Value);

	UFUNCTION(BlueprintCallable)
		void SetMaxPosture(float Value);

	UFUNCTION(BlueprintCallable)
		void SetStamina(float Value);

	UFUNCTION(BlueprintCallable)
		void SetMaxStamina(float Value);

	UFUNCTION(BlueprintCallable)
		void SetBossHealth(float Value);

	UFUNCTION(BlueprintCallable)
		void SetMaxBossHealth(float Value);
	
	UFUNCTION(BlueprintCallable)
		void SetBossPosture(float Value);

	UFUNCTION(BlueprintCallable)
		void SetMaxBossPosture(float Value);
};
