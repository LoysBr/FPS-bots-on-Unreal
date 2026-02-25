// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ZulaOnUE : ModuleRules
{
	public ZulaOnUE(ReadOnlyTargetRules Target) : base(Target)
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
			"ZulaOnUE",
			"ZulaOnUE/Variant_Horror",
			"ZulaOnUE/Variant_Horror/UI",
			"ZulaOnUE/Variant_Shooter",
			"ZulaOnUE/Variant_Shooter/AI",
			"ZulaOnUE/Variant_Shooter/UI",
			"ZulaOnUE/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
