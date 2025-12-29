// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DAIExampleProjectEditorTarget : TargetRules
{
	public DAIExampleProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		// Upgraded include order to UE 5.5 (was Unreal5_4). If future engine upgrades occur, consider EngineIncludeOrderVersion.Latest.
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.AddRange(new string[] { "DAIExampleProject" });
	}
}
