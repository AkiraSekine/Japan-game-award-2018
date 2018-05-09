// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayer.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	alphaEnemy = TSoftClassPtr<ACharacter>(FSoftObjectPath(TEXT("/Game/Blueprints/Reito/Enemy/AI_test/AlphaEnemy"))).LoadSynchronous();
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), alphaEnemy, FoundActors);

	for (auto actor : FoundActors)
	{
		
	}
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddControllerYawInput(cameraInput.Y);
	AddControllerPitchInput(cameraInput.X);

	AddMovementInput(this->GetActorForwardVector(), moveInput.X);
	AddMovementInput(this->GetActorRightVector(), moveInput.Y);
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Camera", IE_Pressed, this, &AMainPlayer::CameraPressed);
	InputComponent->BindAction("Camera", IE_Released, this, &AMainPlayer::CameraReleased);

	InputComponent->BindAxis("MoveForward", this, &AMainPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMainPlayer::Turn);
	InputComponent->BindAxis("LookUp", this, &AMainPlayer::LookUp);
}

