// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "JGA2018CppGameMode.h"
#include "JGA2018CppHUD.h"
#include "JGA2018CppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJGA2018CppGameMode::AJGA2018CppGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AJGA2018CppHUD::StaticClass();
}
