// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GASCharacterMovementComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

UGASCharacterMovementComponent::UGASCharacterMovementComponent()
{
	MovingTag = FGameplayTag::RequestGameplayTag("Character.Movement.Moving");
	InAirTag = FGameplayTag::RequestGameplayTag("Character.Movement.InAir");
}

void UGASCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
	Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);

	// 處理角色移動的Tag
	if (Velocity.Length() > 0.f || Acceleration.Length() > 0.f)
	{
		UAbilitySystemBlueprintLibrary::AddLooseGameplayTags(GetOwner(), FGameplayTagContainer(MovingTag));
	}
	else
	{
		UAbilitySystemBlueprintLibrary::RemoveLooseGameplayTags(GetOwner(), FGameplayTagContainer(MovingTag));
	}

	// 處理角色在空中的Tag
	if (GetGroundDistance() > 200.f)
	{
		UAbilitySystemBlueprintLibrary::AddLooseGameplayTags(GetOwner(), FGameplayTagContainer(InAirTag));
	}
	else
	{
		UAbilitySystemBlueprintLibrary::RemoveLooseGameplayTags(GetOwner(), FGameplayTagContainer(InAirTag));
	}
}

float UGASCharacterMovementComponent::GetGroundDistance() const
{
	if (!CharacterOwner) return 0.f;

	float GroundDistance = 0.f;

	if (MovementMode == MOVE_Walking)
	{
		GroundDistance = 0.f;;
	}
	else
	{
		const UCapsuleComponent* CapsuleComp = CharacterOwner->GetCapsuleComponent();
		const float CapsuleHalfHeight = CapsuleComp->GetUnscaledCapsuleHalfHeight();
		const ECollisionChannel CollisionChannel = (UpdatedComponent ? UpdatedComponent->GetCollisionObjectType() : ECC_Pawn);
		const FVector TraceStart(GetActorLocation());
		const FVector TraceEnd(TraceStart.X, TraceStart.Y, (TraceStart.Z - 10000.f - CapsuleHalfHeight));

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(CharacterOwner);

		FHitResult HitResult;
		GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, CollisionChannel, QueryParams, FCollisionResponseParams());

		if (MovementMode == MOVE_NavWalking)
			GroundDistance = 0.f;
		else if (HitResult.bBlockingHit)
			GroundDistance = FMath::Max((HitResult.Distance - CapsuleHalfHeight), 0.f);
	}

	return GroundDistance;
}
