// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "JGA2018CppHUD.generated.h"

UCLASS()
class AJGA2018CppHUD : public AHUD
{
	GENERATED_BODY()

public:
	AJGA2018CppHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

