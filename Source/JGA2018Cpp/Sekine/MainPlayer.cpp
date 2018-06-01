// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

// Sets default values
AMainPlayer::AMainPlayer() :
	condition(EPlayerCondition::Normal)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddControllerYawInput(cameraInput.Y);
	AddControllerPitchInput(cameraInput.X);

	if (condition != EPlayerCondition::Locker)
	{
		if (moveInput.X > 0)
			isWalk = true;
		else
			isWalk = false;

		AddMovementInput(this->GetActorForwardVector(), moveInput.X);
		AddMovementInput(this->GetActorRightVector(), moveInput.Y);
	}

	GetCharacterMovement()->MaxWalkSpeed = ((sprint && !holdCamera) ? sprintSpeed : walkSpeed);

	if (holdCamera)
	{
		battery -= DeltaTime * 0.5f;
	}
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMainPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMainPlayer::Turn);
	InputComponent->BindAxis("LookUp", this, &AMainPlayer::LookUp);
}

void AMainPlayer::AddBattery(int value)
{
	battery += value;

	if (battery > 100.f)
	{
		battery = 100.f;
	}
}

