// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GASAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API UGASAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	UGASAbilitySystemComponent();		

	// �N��J��O�[�J������AbilitySpecHandle�Ʋ�;
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);

	// �B�Q�b���V�ݭn�E������J�ޯ� (�bPlayerController��PostProcessInput�ϥ�)
	void ProcessAbilityInput(float DeltaTime, bool bGamePaused);

	// �M���U��J���A��AbilitySpecHandle
	void ClearAbilityInput();

	// Enable BatchRPC
	virtual bool ShouldDoServerAbilityRPCBatch() const override;

	UFUNCTION(BlueprintCallable)
		bool BatchRPCTryActivateAbility(const FGameplayAbilitySpecHandle& InAbilityHandle, bool EndAbilityImmediately);

	UFUNCTION(BlueprintCallable)
		void ReleaseInputAbilityByTag(const FGameplayTag& InputTag);

protected:

	//~ AbilitySystemComponent Interface
	virtual void AbilitySpecInputPressed(FGameplayAbilitySpec& Spec) override;
	virtual void AbilitySpecInputReleased(FGameplayAbilitySpec& Spec) override;
	//~

protected:

	// �B�z�b���V����J�ޯ� (���U�B��}�B����)
	TArray<FGameplayAbilitySpecHandle> InputPressedSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputReleasedSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputHeldSpecHandles;

};
