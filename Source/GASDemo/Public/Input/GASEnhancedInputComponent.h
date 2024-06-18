// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "InputConfig.h"
#include "GameplayTagContainer.h"
#include "GASEnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API UGASEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	// 通過Tag綁定IA
	template<class UserClass, typename FuncType>
	void BindActionByTag(const UInputConfig* InputConfig, const FName& InputTagName, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func);

	// 通過Tag觸發能力
	template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
	void BindAbilityAction(const UInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc);
	
};

template<class UserClass, typename FuncType>
void UGASEnhancedInputComponent::BindActionByTag(const UInputConfig* InputConfig, const FName& TagName, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func)
{
	check(InputConfig);

	FGameplayTag InputTag = FGameplayTag::RequestGameplayTag(TagName);
	if (const UInputAction* IA = InputConfig->FindInputActionByTag(InputTag))
	{
		BindAction(IA, TriggerEvent, Object, Func);
	}
}

template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
void UGASEnhancedInputComponent::BindAbilityAction(const UInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc)
{
	check(InputConfig);

	for (const FTaggedInputAction& Action : InputConfig->AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag.IsValid())
		{
			if (PressedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, PressedFunc, Action.InputTag);
			}
			if (ReleasedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, Action.InputTag);
			}
		}
	}
}
