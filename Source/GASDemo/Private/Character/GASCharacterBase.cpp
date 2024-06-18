// Copyright Epic Games, Inc. All Rights Reserved.

#include "Character/GASCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Character/GASCharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Input/GASEnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "Player/GASPlayerState.h"
#include "Player/GASPlayerController.h"
#include "AbilitySystem/GASAbilitySet.h"
#include "AbilitySystem/AttributeSets/GASCharacterAttributeSet.h"
#include "Weapon/WeaponBase.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"
#include "Widget/MainWidget.h"
#include "Components/SphereComponent.h"

//////////////////////////////////////////////////////////////////////////
// AGASCharacterBase

AGASCharacterBase::AGASCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UGASCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	MaxWalkSpeed = 500.f;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	bUseControllerRotationYaw = true;

	UGASCharacterMovementComponent* GASMovementComp = Cast<UGASCharacterMovementComponent>(GetCharacterMovement());
	GASMovementComp->bOrientRotationToMovement = false;
	GASMovementComp->JumpZVelocity = 400.f;
	GASMovementComp->AirControl = 0.35f;
	GASMovementComp->MaxWalkSpeed = MaxWalkSpeed;
	GASMovementComp->MinAnalogWalkSpeed = 20.f;
	GASMovementComp->BrakingDecelerationWalking = 2000.f;
	GASMovementComp->MaxStepHeight = 60.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; 
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false; 
	
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;

	RetargetingMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RetargetingMesh"));
	RetargetingMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RetargetingMesh->SetupAttachment(GetMesh());

	PreDetect = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PreDetect"));
	PreDetect->SetCapsuleSize(100.f, 100.f);
	PreDetect->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	PreDetect->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	PreDetect->SetupAttachment(RootComponent);

	LockRange = 2500.f;
	LockArea = CreateDefaultSubobject<USphereComponent>(TEXT("LockArea"));
	LockArea->SetupAttachment(RootComponent);

	WeaponClass = AWeaponBase::StaticClass();
	WeaponSocket = "weaponSocket_r";
	TracePointCount = 5;
	DetectHitTick = .005f;
}

void AGASCharacterBase::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	SpawnWeapon();

	LockArea->SetSphereRadius(LockRange);
	LockArea->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::BeginEnterLockArea);
}

void AGASCharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AGASCharacterBase, ControllerInput, COND_OwnerOnly);
}

void AGASCharacterBase::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UGASEnhancedInputComponent* EnhancedInputComponent = CastChecked<UGASEnhancedInputComponent>(PlayerInputComponent)) {
	
		//Ability
		EnhancedInputComponent->BindAbilityAction(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased);

		//Move
		EnhancedInputComponent->BindActionByTag(InputConfig, "Input.Move", ETriggerEvent::Triggered, this, &ThisClass::Move);

		//Look
		EnhancedInputComponent->BindActionByTag(InputConfig, "Input.Look", ETriggerEvent::Triggered, this, &ThisClass::Look);

		//Targeting
		EnhancedInputComponent->BindActionByTag(InputConfig, "Input.TargetingConfirm", ETriggerEvent::Triggered, ASC, &UAbilitySystemComponent::LocalInputConfirm);
		EnhancedInputComponent->BindActionByTag(InputConfig, "Input.TargetingCancel", ETriggerEvent::Triggered, ASC, &UAbilitySystemComponent::LocalInputCancel);
	}

}

UAbilitySystemComponent* AGASCharacterBase::GetAbilitySystemComponent() const
{
	return ASC ? ASC : nullptr;
}

void AGASCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Server初始化ASC信息
	AGASPlayerState* PS = Cast<AGASPlayerState>(GetPlayerState());
	if (PS)
	{
		ASC = Cast<UGASAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		if (ASC)
		{
			ASC->InitAbilityActorInfo(PS, this);
			if (AbilitySet)
			{
				AbilitySet->GiveToAbilitySystem(ASC);
			}
			AttributeSet = ASC->GetSet<UGASCharacterAttributeSet>();

			ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChangedNative);
			ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStaminaAttribute()).AddUObject(this, &ThisClass::OnStaminaChangedNative);
			ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetPostureAttribute()).AddUObject(this, &ThisClass::OnPostureChangedNative);
			ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMoveSpeedRateAttribute()).AddUObject(this, &ThisClass::OnMoveSpeedRateChangedNative);
		}
	}
}

void AGASCharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Client初始化ASC信息 (用於GA的本地預測)
	AGASPlayerState* PS = Cast<AGASPlayerState>(GetPlayerState());
	if (PS)
	{
		ASC = Cast<UGASAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		if (ASC)
		{
			ASC->InitAbilityActorInfo(PS, this);
			AttributeSet = ASC->GetSet<UGASCharacterAttributeSet>();
		}
	}
}

void AGASCharacterBase::BeginEnterLockArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 忽略自身並只更新對象一次
	if (this == OtherActor || Target == OtherActor) return;
	if (AGASCharacterBase* Character = Cast<AGASCharacterBase>(OtherActor))
	{
		Target = Character;

		float HP = 0.f, MaxHP = 0.f;
		float Posture = 0.f, MaxPosture = 0.f;

		if (IsPlayerControlled())
		{
			GetGASPlayerController()->HUDWidget->ShowBossStatus(true);

			Target->GetHealth(HP, MaxHP);
			GetGASPlayerController()->HUDWidget->SetBossHealth(HP);
			GetGASPlayerController()->HUDWidget->SetMaxBossHealth(MaxHP);

			Target->GetPosture(Posture, MaxPosture);
			GetGASPlayerController()->HUDWidget->SetBossPosture(Posture);
			GetGASPlayerController()->HUDWidget->SetMaxBossPosture(MaxPosture);

			K2_BeginEnterLockArea();
		}
	}
}

void AGASCharacterBase::OnHealthChangedNative(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);

	if (IsPlayerControlled())
	{
		float CurrentValue = 0.f, MaxValue = 0.f;
		GetHealth(CurrentValue, MaxValue);

		if (GetGASPlayerController()->HUDWidget)
		{
			GetGASPlayerController()->HUDWidget->SetHealth(CurrentValue);
			GetGASPlayerController()->HUDWidget->SetMaxHealth(MaxValue);
		}
	}
	else
	{
		if (Target)
		{
			// 更改Boss相關UI
			float CurrentValue = 0.f, MaxValue = 0.f;
			GetHealth(CurrentValue, MaxValue);
			if (Target->GetGASPlayerController())
			{
				Target->GetGASPlayerController()->HUDWidget->SetBossHealth(CurrentValue);
				Target->GetGASPlayerController()->HUDWidget->SetMaxBossHealth(MaxValue);
			}
		}
	}
}

void AGASCharacterBase::OnStaminaChangedNative(const FOnAttributeChangeData& Data)
{
	OnStaminaChanged(Data.OldValue, Data.NewValue);

	if (IsPlayerControlled())
	{
		float CurrentValue = 0.f, MaxValue = 0.f;
		GetStamina(CurrentValue, MaxValue);

		if (GetGASPlayerController()->HUDWidget)
		{
			GetGASPlayerController()->HUDWidget->SetStamina(CurrentValue);
			GetGASPlayerController()->HUDWidget->SetMaxStamina(MaxValue);
		}
	}
}

void AGASCharacterBase::OnPostureChangedNative(const FOnAttributeChangeData& Data)
{
	OnPostureChanged(Data.OldValue, Data.NewValue);

	if (IsPlayerControlled())
	{
		float CurrentValue = 0.f, MaxValue = 0.f;
		GetPosture(CurrentValue, MaxValue);

		if (GetGASPlayerController()->HUDWidget)
		{
			GetGASPlayerController()->HUDWidget->SetPosture(CurrentValue);
			GetGASPlayerController()->HUDWidget->SetMaxPosture(MaxValue);
		}
	}
	else
	{
		if (Target)
		{
			// 更改Boss相關UI
			float CurrentValue = 0.f, MaxValue = 0.f;
			GetPosture(CurrentValue, MaxValue);
			if (Target->GetGASPlayerController())
			{
				Target->GetGASPlayerController()->HUDWidget->SetBossPosture(CurrentValue);
				Target->GetGASPlayerController()->HUDWidget->SetMaxBossPosture(MaxValue);
			}
		}
	}
}

void AGASCharacterBase::OnMoveSpeedRateChangedNative(const FOnAttributeChangeData& Data)
{
	OnMoveSpeedRateChanged(Data.OldValue, Data.NewValue);
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed * Data.NewValue;
}

void AGASCharacterBase::GetHealth(float& CurrentValue, float& MaxValue) const
{
	if (AttributeSet)
	{
		CurrentValue = AttributeSet->GetHealth();
		MaxValue = AttributeSet->GetMaxHealth();
	}
}

void AGASCharacterBase::GetPosture(float& CurrentValue, float& MaxValue) const
{
	if (AttributeSet)
	{
		CurrentValue = AttributeSet->GetPosture();
		MaxValue = AttributeSet->GetMaxPosture();
	}
}

void AGASCharacterBase::GetStamina(float& CurrentValue, float& MaxValue) const
{
	if (AttributeSet)
	{
		CurrentValue = AttributeSet->GetStamina();
		MaxValue = AttributeSet->GetMaxStamina();
	}
}

void AGASCharacterBase::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);

		FVector Forward = ForwardDirection * MovementVector.Y;
		FVector Right = RightDirection * MovementVector.X;

		ServerGetControllerInput(Forward + Right);
	}
}

void AGASCharacterBase::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGASCharacterBase::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (ASC)
		ASC->AbilityInputTagPressed(InputTag);
}

void AGASCharacterBase::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (ASC)
		ASC->AbilityInputTagReleased(InputTag);
}

void AGASCharacterBase::Equipped()
{
	GetMesh()->LinkAnimClassLayers(EquipmentAnimLayer);
	K2_OnEquipped();
}

void AGASCharacterBase::Unequipped()
{
	GetMesh()->LinkAnimClassLayers(UnequipmentAnimLayer);
	K2_OnUnequipped();
}

AGASPlayerController* AGASCharacterBase::GetGASPlayerController() const
{
	return Controller ? Cast<AGASPlayerController>(Controller) : nullptr;
}

void AGASCharacterBase::ServerGetControllerInput_Implementation(FVector InControllerInput)
{
	// 將客戶端的控制輸入賦值給Server的可複製變量 ControllerInput
	ControllerInput = InControllerInput;
}

void AGASCharacterBase::SpawnWeapon()
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.Owner = this;

	Weapon = GetWorld()->SpawnActor<AWeaponBase>(WeaponClass, Params);
	Weapon->AttachToComponent(RetargetingMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponSocket);
	AddTracePoints();

	K2_SpawnWeapon();
}

void AGASCharacterBase::BeginDetectAttackHit()
{
	HitActors.Reset();
	UpdateTracePointsLocation();
	GetWorld()->GetTimerManager().SetTimer(DetectHitHandle, this, &ThisClass::DetectHitTimerFunction, DetectHitTick, true);
	ASC->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag("Ability.State.Attack.Hit"));
}

void AGASCharacterBase::EndDetectAttackHit()
{
	GetWorld()->GetTimerManager().ClearTimer(DetectHitHandle);
	ASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag("Ability.State.Attack.Hit"));
}

void AGASCharacterBase::DetectHitTimerFunction()
{
	for (int32 i = 0;i < TracePoints.Num();i++)
	{
		FVector TraceStart = PreviousTracePointsLocation[i];
		FVector TraceEnd = TracePoints[i]->GetComponentLocation();

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

		TArray<AActor*> ActorsToIgnore;
		GetAllChildActors(ActorsToIgnore);
		ActorsToIgnore.Add(this);
		ActorsToIgnore.Add(Weapon);

		TArray<FHitResult> OutHits;
		bool bHit = UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), TraceStart, TraceEnd, Weapon->HitRadius,
			ObjectTypes, false, ActorsToIgnore, EDrawDebugTrace::None, OutHits, true);

		if (bHit)
		{
			// 被攻擊者的事件Tag
			FGameplayTag EventTag = FGameplayTag::RequestGameplayTag("Event.Attack.Hit");

			FGameplayEventData Payload;
			Payload.EventTag = EventTag;
			Payload.Instigator = this;

			for (const FHitResult& Hit : OutHits)
			{
				// 沒有ASC且已存在於HitActors中就跳過
				if(!UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Hit.GetActor())) continue;
				if (HitActors.Find(Hit.GetActor()) > INDEX_NONE) continue;

				HitActors.AddUnique(Hit.GetActor());
				Payload.Target = Hit.GetActor();

				// 命中結果的TargetData
				// 需要寄給受擊者的TargetData
				FGameplayAbilityTargetDataHandle TargetData;
				FGameplayAbilityTargetData_SingleTargetHit* Data = new FGameplayAbilityTargetData_SingleTargetHit();
				Data->HitResult = Hit;
				TargetData.Add(Data);
				Payload.TargetData = TargetData;
				UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Hit.GetActor(), EventTag, Payload);
			}
		}
	}

	UpdateTracePointsLocation();
}

void AGASCharacterBase::UpdateTracePointsLocation()
{
	for (int32 i = 0;i < TracePoints.Num();i++)
	{
		PreviousTracePointsLocation[i] = TracePoints[i]->GetComponentLocation();
	}
}

void AGASCharacterBase::AddTracePoints()
{
	FTransform TraceStart = Weapon->WeaponMesh->GetSocketTransform("TraceStart", RTS_Component);
	FTransform TraceEnd = Weapon->WeaponMesh->GetSocketTransform("TraceEnd", RTS_Component);
	float PointDistance = (TraceEnd.GetLocation().Y - TraceStart.GetLocation().Y) / TracePointCount;

	for (int32 i = 1;i <= TracePointCount;i++)
	{
		FTransform TracePointTrans(TraceStart);
		FVector PointLoc(TraceStart.GetLocation());
		PointLoc.Y = TraceStart.GetLocation().Y + PointDistance * i;
		TracePointTrans.SetLocation(PointLoc);

		if (UBoxComponent* BoxComp = Cast<UBoxComponent>(Weapon->AddComponentByClass(
			UBoxComponent::StaticClass(), false, TracePointTrans, false)))
		{
			BoxComp->AttachToComponent(Weapon->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
			BoxComp->SetBoxExtent(FVector(5.f));
			TracePoints.Add(BoxComp);
			PreviousTracePointsLocation.Add(BoxComp->GetComponentLocation());
		}
	}
}
