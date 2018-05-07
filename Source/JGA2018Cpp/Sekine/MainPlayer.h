// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

UCLASS()
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
};
