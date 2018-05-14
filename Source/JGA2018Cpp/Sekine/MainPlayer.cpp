// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters spawnInfo;

	chargerClass = TSoftClassPtr<AActor>(FSoftObjectPath(TEXT("Game/Blueprints/Sekine/BP_Charger.BP_Charger_C"))).LoadSynchronous();

	charger = GetWorld()->SpawnActor<AActor>(chargerClass, spawnInfo);
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddControllerYawInput(cameraInput.Y);
	AddControllerPitchInput(cameraInput.X);

	if (condition != EPlayerCondition::Locker)
	{
		AddMovementInput(this->GetActorForwardVector(), moveInput.X);
		AddMovementInput(this->GetActorRightVector(), moveInput.Y);
	}

	GetCharacterMovement()->MaxWalkSpeed = ((sprint && !holdCamera) ? sprintSpeed : walkSpeed);

	if (holdCamera)
	{
		battery -= 2.f * DeltaTime;
	}

	if (action)
	{
		FHitResult hitActor;

		ActorLineTraceSingle(hitActor, this->GetActorLocation(), this->GetActorLocation() + GetActorForwardVector()*50.f, ECollisionChannel::ECC_Visibility, FCollisionQueryParams());

		if (Cast<AActor>(hitActor.Actor->GetClass()) && canCharge)
		{
			battery += 10;
		}
	}
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Camera", IE_Pressed, this, &AMainPlayer::CameraPressed);
	InputComponent->BindAction("Camera", IE_Released, this, &AMainPlayer::CameraReleased);
	InputComponent->BindAction("Sprint", IE_Pressed, this, &AMainPlayer::SprintPressed);
	InputComponent->BindAction("Sprint", IE_Released, this, &AMainPlayer::SprintReleased);
	InputComponent->BindAction("Action", IE_Pressed, this, &AMainPlayer::ActionPressed);
	InputComponent->BindAction("Action", IE_Released, this, &AMainPlayer::ActionReleased);

	InputComponent->BindAxis("MoveForward", this, &AMainPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMainPlayer::Turn);
	InputComponent->BindAxis("LookUp", this, &AMainPlayer::LookUp);
}

