// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tp2IaThiago : ModuleRules
{
	public Tp2IaThiago(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
