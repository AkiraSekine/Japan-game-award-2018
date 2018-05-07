// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshActor.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

/**
 * 
 */
UCLASS()
class JGA2018CPP_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	
public:

	TSubclassOf<AHUD> HUD;

	AMainPlayerController();


};
