// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class JapanGameAwards2018Target : TargetRules
{
	public JapanGameAwards2018Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "JapanGameAwards2018" } );
	}
}
