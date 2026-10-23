using UnrealBuildTool;

public class InteractionToolkit : ModuleRules
{
    public InteractionToolkit(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "UMG"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
        });
    }
}