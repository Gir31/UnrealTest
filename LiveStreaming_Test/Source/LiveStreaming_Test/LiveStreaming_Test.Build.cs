// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LiveStreaming_Test : ModuleRules
{
	public LiveStreaming_Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"LiveStreaming_Test",
			"LiveStreaming_Test/Variant_Platforming",
			"LiveStreaming_Test/Variant_Platforming/Animation",
			"LiveStreaming_Test/Variant_Combat",
			"LiveStreaming_Test/Variant_Combat/AI",
			"LiveStreaming_Test/Variant_Combat/Animation",
			"LiveStreaming_Test/Variant_Combat/Gameplay",
			"LiveStreaming_Test/Variant_Combat/Interfaces",
			"LiveStreaming_Test/Variant_Combat/UI",
			"LiveStreaming_Test/Variant_SideScrolling",
			"LiveStreaming_Test/Variant_SideScrolling/AI",
			"LiveStreaming_Test/Variant_SideScrolling/Gameplay",
			"LiveStreaming_Test/Variant_SideScrolling/Interfaces",
			"LiveStreaming_Test/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
