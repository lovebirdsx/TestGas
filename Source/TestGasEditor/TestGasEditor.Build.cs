using UnrealBuildTool;

public class TestGasEditor: ModuleRules
{
    public TestGasEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"});
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "LiveCoding",
            "SessionFrontend"
        });
    }
}
