// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPShooterEditor : ModuleRules
{
	public FPShooterEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "MainFrame" , "Slate", "SlateCore", "EditorStyle"});
		PublicDependencyModuleNames.Add("FPShooter");
		PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd" });
	}
}
