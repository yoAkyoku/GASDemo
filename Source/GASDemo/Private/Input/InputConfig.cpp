// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/InputConfig.h"

const UInputAction* UInputConfig::FindInputActionByTag(const FGameplayTag& InputTag) const
{
	if (!InputTag.IsValid()) return nullptr;

	for (const FTaggedInputAction& TaggedInputAction : NativeInputActions)
	{
		if (TaggedInputAction.InputTag == InputTag)
			return TaggedInputAction.InputAction;
	}

	return nullptr;
}