// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPShooter : ModuleRules
{
	public FPShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
