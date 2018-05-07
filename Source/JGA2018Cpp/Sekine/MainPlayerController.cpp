// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController.h"

AMainPlayerController::AMainPlayerController()
{
	static ConstructorHelpers::FObjectFinder<UClass> foundActor(TEXT("Game/Brueprints/BP_MainHUD.BP_MainHUD_C"));
	HUD = foundActor.Object;
}
