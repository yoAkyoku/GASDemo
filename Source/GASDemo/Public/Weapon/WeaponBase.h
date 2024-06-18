// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class GASDEMO_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	

	AWeaponBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float HitRadius;

protected:

	virtual void BeginPlay() override;
};
