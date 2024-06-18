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

	// 將輸入能力加入對應的AbilitySpecHandle數組;
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);

	// 處利在本幀需要激活的輸入技能 (在PlayerController的PostProcessInput使用)
	void ProcessAbilityInput(float DeltaTime, bool bGamePaused);

	// 清楚各輸入狀態的AbilitySpecHandle
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

	// 處理在本幀的輸入技能 (按下、放開、按住)
	TArray<FGameplayAbilitySpecHandle> InputPressedSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputReleasedSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputHeldSpecHandles;

};
