// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

UENUM()
enum class EPlayerCondition : uint8
{
	Normal, Locker
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

	UPROPERTY(BlueprintReadOnly)
		float walkSpeed = 300;
	UPROPERTY(BlueprintReadOnly)
		float sprintSpeed = 450;

	UPROPERTY(BlueprintReadWrite)
		EPlayerCondition condition = EPlayerCondition::Normal;

	UPROPERTY(BlueprintReadWrite)
		bool holdCamera = false;

	UPROPERTY(BlueprintReadWrite)
		bool canCharge = false;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	bool camera = false;
	bool sprint = false;
	bool action = false;

	FVector2D moveInput;
	FVector2D cameraInput;

	float battery = 100.f;

	TSubclassOf<class AActor> chargerClass;
	AActor * charger;

	inline void CameraPressed()
	{
		camera = true;
	}
	inline void CameraReleased()
	{
		camera = false;
	}
	inline void SprintPressed()
	{
		sprint = true;
	}
	inline void SprintReleased()
	{
		sprint = false;
	}
	inline void ActionPressed()
	{
		action = true;
	}
	inline void ActionReleased()
	{
		action = false;
	}

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
};
