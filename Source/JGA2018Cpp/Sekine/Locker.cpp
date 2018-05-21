// Fill out your copyright notice in the Description page of Project Settings.

#include "Locker.h"


// Sets default values
ALocker::ALocker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALocker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALocker::Enter()
{
	switch (mainPlayer->condition)
	{
	case EPlayerCondition::Normal:

		mainPlayer->SetActorLocation(this->GetActorLocation());
		playerController->SetControlRotation(this->GetActorRotation());

		mainPlayer->condition = EPlayerCondition::Locker;

		break;

	case EPlayerCondition::Locker:

		mainPlayer->SetActorLocation(this->GetActorLocation() + this->GetActorForwardVector()*125.f);
		playerController->SetControlRotation(this->GetActorRotation());

		mainPlayer->condition = EPlayerCondition::Normal;

		break;
	}
}

