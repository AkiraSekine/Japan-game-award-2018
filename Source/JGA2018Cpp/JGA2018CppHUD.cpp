// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "JGA2018CppHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

AJGA2018CppHUD::AJGA2018CppHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/DefaultItems/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}


void AJGA2018CppHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}
