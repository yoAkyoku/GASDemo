// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponBase.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetRootComponent(WeaponMesh);

	HitRadius = 5.f;
}



void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
	// �b�����Źϸ˳Ʈɳ]�mOwningActor
	//OwningActor = GetAttachParentActor();
}



