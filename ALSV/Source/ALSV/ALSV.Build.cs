// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ALSV : ModuleRules
{
	public ALSV(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange( new string[] {
			"ALSV"
			// ... add public include paths required here ...
		});

        PrivateIncludePaths.AddRange(new string[] {
            "ALSV"
			// ... add public include paths required here ...
		});

        PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core",
			"NetCore", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay"
		});
	}
}
