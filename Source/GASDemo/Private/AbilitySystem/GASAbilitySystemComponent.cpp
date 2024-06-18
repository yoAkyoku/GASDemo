// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GASAbilitySystemComponent.h"

UGASAbilitySystemComponent::UGASAbilitySystemComponent()
{
	ClearAbilityInput();
}

void UGASAbilitySystemComponent::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (InputTag.IsValid())
	{
		for (const FGameplayAbilitySpec& Spec : ActivatableAbilities.Items)
		{
			if (Spec.Ability && Spec.DynamicAbilityTags.HasTagExact(InputTag))
			{
				InputPressedSpecHandles.AddUnique(Spec.Handle);
				InputHeldSpecHandles.AddUnique(Spec.Handle);
			}
		}
	}
}

void UGASAbilitySystemComponent::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (InputTag.IsValid())
	{
		for (const FGameplayAbilitySpec& Spec : ActivatableAbilities.Items)
		{
			if (Spec.Ability && Spec.DynamicAbilityTags.HasTagExact(InputTag))
			{
				InputReleasedSpecHandles.AddUnique(Spec.Handle);
				InputHeldSpecHandles.Remove(Spec.Handle);
			}
		}
	}
}

void UGASAbilitySystemComponent::ProcessAbilityInput(float DeltaTime, bool bGamePaused)
{
	// �ݭn�E����GA
	static TArray<FGameplayAbilitySpecHandle> AbilitiesToActivate;

	// �B�z�b���V����J����ޯ�
	for (const FGameplayAbilitySpecHandle& Handle : InputHeldSpecHandles)
	{
		if (const FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Handle))
		{
			if (Spec->Ability && !Spec->IsActive())
			{
				AbilitiesToActivate.AddUnique(Handle);
			}
		}
	}

	// �B�z�b���V����J���U�ޯ�
	for (const FGameplayAbilitySpecHandle& Handle : InputPressedSpecHandles)
	{
		if (FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Handle))
		{
			if (!Spec->Ability) continue;
			if (Spec->IsActive())
			{
				AbilitySpecInputPressed(*Spec);
			}
			else
			{
				AbilitiesToActivate.AddUnique(Handle);
			}
		}
	}

	// �E���Ҧ��Ӧ۫�����O
	for (const FGameplayAbilitySpecHandle& Handle : AbilitiesToActivate)
	{
		// �ϥ�BatchRPC
		FScopedServerAbilityRPCBatcher RPCBatcher(this, Handle);
		TryActivateAbility(Handle);
	}

	// �B�z�b���V����J��}�ޯ�
	for (const FGameplayAbilitySpecHandle& Handle : InputReleasedSpecHandles)
	{
		if (FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Handle))
		{
			if (!Spec->Ability) continue;
			if (Spec->IsActive())
			{
				AbilitySpecInputReleased(*Spec);
			}
		}
	}

	// �M��
	AbilitiesToActivate.Reset();
	ClearAbilityInput();
}

void UGASAbilitySystemComponent::ClearAbilityInput()
{
	InputPressedSpecHandles.Reset();
	InputReleasedSpecHandles.Reset();
	InputHeldSpecHandles.Reset();
}

bool UGASAbilitySystemComponent::ShouldDoServerAbilityRPCBatch() const
{
	return true;
}

bool UGASAbilitySystemComponent::BatchRPCTryActivateAbility(const FGameplayAbilitySpecHandle& InAbilityHandle, bool EndAbilityImmediately)
{
	bool bActivated = false;

	if (InAbilityHandle.IsValid())
	{
		FScopedServerAbilityRPCBatcher RPCBatcher(this, InAbilityHandle);
		bActivated = TryActivateAbility(InAbilityHandle, true);

		// �O�_�b�E����N������O
		if (EndAbilityImmediately)
		{
			CancelAbilityHandle(InAbilityHandle);
		}
	}

	return bActivated;
}

void UGASAbilitySystemComponent::ReleaseInputAbilityByTag(const FGameplayTag& InputTag)
{
	AbilityInputTagReleased(InputTag);

	for (const FGameplayAbilitySpecHandle& Handle : InputReleasedSpecHandles)
	{
		if (FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Handle))
		{
			if (!Spec->Ability) continue;
			if (Spec->IsActive())
			{
				AbilitySpecInputReleased(*Spec);
			}
		}
	}
}

void UGASAbilitySystemComponent::AbilitySpecInputPressed(FGameplayAbilitySpec& Spec)
{
	Super::AbilitySpecInputPressed(Spec);

	//�եο�J���ƻs�ƥ� (WaitInputPress��Ability Task�~�ॿ�`�ϥ�)
	if (Spec.IsActive())
		InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputPressed, Spec.Handle, Spec.ActivationInfo.GetActivationPredictionKey());
}

void UGASAbilitySystemComponent::AbilitySpecInputReleased(FGameplayAbilitySpec& Spec)
{
	Super::AbilitySpecInputReleased(Spec);

	//�եο�J���ƻs�ƥ� (WaitInputRelease��Ability Task�~�ॿ�`�ϥ�)
	if (Spec.IsActive())
		InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputReleased, Spec.Handle, Spec.ActivationInfo.GetActivationPredictionKey());
}
