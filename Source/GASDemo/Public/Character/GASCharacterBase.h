// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "GameplayEffectTypes.h"
#include "GASCharacterBase.generated.h"

class AGASPlayerController;

UCLASS(config=Game)
class AGASCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()


public:

	AGASCharacterBase(const FObjectInitializer& ObjectInitializer);

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* FollowCamera;

	/** Retargeting Mesh*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Retargeting)
		class USkeletalMeshComponent* RetargetingMesh;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|Input")
		class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|Input")
		class UInputConfig* InputConfig;

	UPROPERTY(BlueprintReadOnly, Category = Ability)
		class UGASAbilitySystemComponent* ASC;

	UPROPERTY(BlueprintReadOnly, Category = Ability)
		const class UGASCharacterAttributeSet* AttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Ability")
		class UGASAbilitySet* AbilitySet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Movement")
		float MaxWalkSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GAS|Weapon")
		class TSubclassOf<UAnimInstance> EquipmentAnimLayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GAS|Weapon")
		class TSubclassOf<UAnimInstance> UnequipmentAnimLayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|Input")
		UCapsuleComponent* PreDetect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GAS|Weapon")
		TSubclassOf<class AWeaponBase> WeaponClass;

	UPROPERTY(BlueprintReadWrite, Category = "GAS|Weapon")
		class AWeaponBase* Weapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Weapon")
		FName WeaponSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS|Weapon")
		int32 TracePointCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS|Weapon")
		float DetectHitTick;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class USphereComponent* LockArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LockRange;

	// input is a Vector2D
	UPROPERTY(BlueprintReadOnly, Replicated)
		FVector ControllerInput;

	// 攻擊目標
	UPROPERTY(BlueprintReadWrite)
		AGASCharacterBase* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS|Combat")
		bool bLockOnTarget;

public:

	//ASC Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~
	
	//~Pawn Interface
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	//~

	// 將客戶端的控制輸入賦值給Server的可複製變量 ControllerInput
	UFUNCTION(BlueprintCallable, Server, Unreliable)
		void ServerGetControllerInput(FVector InControllerInput);

	UFUNCTION(BlueprintCallable)
		AGASPlayerController* GetGASPlayerController() const;

	UFUNCTION(BlueprintCallable)
		void AddTracePoints();

	UFUNCTION(BlueprintCallable)
		void BeginDetectAttackHit();

	UFUNCTION(BlueprintCallable)
		void EndDetectAttackHit();

	UFUNCTION(BlueprintCallable)
		void Equipped();
	
	UFUNCTION(BlueprintCallable)
		void Unequipped();

	UFUNCTION(BlueprintImplementableEvent)
		void K2_OnEquipped();

	UFUNCTION(BlueprintImplementableEvent)
		void K2_OnUnequipped();

	UFUNCTION(BlueprintImplementableEvent)
		void K2_SpawnWeapon();


	// 屬性值改變時調用
	void OnHealthChangedNative(const FOnAttributeChangeData& Data);
	void OnStaminaChangedNative(const FOnAttributeChangeData& Data);
	void OnPostureChangedNative(const FOnAttributeChangeData& Data);
	void OnMoveSpeedRateChangedNative(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent)
		void OnHealthChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent)
		void OnStaminaChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent)
		void OnPostureChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent)
		void OnMoveSpeedRateChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintPure)
		void GetHealth(float& CurrentValue, float& MaxValue) const;

	UFUNCTION(BlueprintPure)
		void GetPosture(float& CurrentValue, float& MaxValue) const;

	UFUNCTION(BlueprintPure)
		void GetStamina(float& CurrentValue, float& MaxValue) const;

protected:

	//~ Input Event
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	//~

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	void UpdateTracePointsLocation();

	// 攻擊檢測
	void DetectHitTimerFunction();

	void SpawnWeapon();

	UFUNCTION()
		void BeginEnterLockArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
		void K2_BeginEnterLockArea();

protected:

	FTimerHandle DetectHitHandle;

	// 添加的檢測點
	UPROPERTY()
		TArray<class UBoxComponent*> TracePoints;

	// 前檢測點位置
	UPROPERTY()
		TArray<FVector> PreviousTracePointsLocation;

	// 被攻擊的Actors
	TArray<AActor*> HitActors;
};

