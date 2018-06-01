// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

UENUM(BlueprintType)
enum class EPlayerCondition : uint8
{
	Normal UMETA(DisplayName = "Normal"),
	Locker UMETA(DisplayName = "Locker")
};

UCLASS(BlueprintType)
class JGA2018CPP_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadWrite)
		bool action = false;
	UPROPERTY(BlueprintReadWrite)
		bool camera = false;
	UPROPERTY(BlueprintReadWrite)
		bool sprint = false;

	UPROPERTY(BlueprintReadOnly)
		float walkSpeed = 300;
	UPROPERTY(BlueprintReadOnly)
		float sprintSpeed = 450;

	UPROPERTY(BlueprintReadWrite)
		EPlayerCondition condition;

	UPROPERTY(BlueprintReadWrite)
		bool holdCamera = false;

	UPROPERTY(BlueprintReadWrite)
		bool canCharge = false;

	UPROPERTY(BlueprintReadWrite)
		bool haveKey = false;

	UPROPERTY(BlueprintReadOnly)
		bool isWalk = false;

	UPROPERTY(BlueprintReadWrite)
		float battery = 100.f;

	UPROPERTY(BlueprintReadWrite)
		AActor * overlapActor;

	UPROPERTY(BlueprintReadWrite)
		AActor * frontActor;

	UPROPERTY(BlueprintReadWrite)
		APlayerController * playerController;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	FVector2D moveInput;
	FVector2D cameraInput;

	inline void MoveForward(float axisValue)
	{
		moveInput.X = axisValue;
	}
	inline void MoveRight(float axisValue)
	{
		moveInput.Y = axisValue;
	}
	inline void Turn(float axisValue)
	{
		cameraInput.Y = axisValue;
	}
	inline void LookUp(float axisValue)
	{
		cameraInput.X = axisValue;
	}

	UFUNCTION(BlueprintCallable)
		void AddBattery(int value);
};
