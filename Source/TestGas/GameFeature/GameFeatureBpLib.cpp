#include "GameFeatureBpLib.h"
#include "GameFeaturesSubsystem.h"
#include "GameFeaturesProjectPolicies.h"
#include "GameFeaturePluginOperationResult.h"

FString UGameFeatureBpLib::GetGameFeatureStatus(UGameFeaturesSubsystem *Subsystem, const FString &InFeature)
{
    FString PluginURL;
    bool bOk = Subsystem->GetPluginURLByName(InFeature, PluginURL);
    if (bOk)
    {
        if (Subsystem->IsGameFeaturePluginActive(PluginURL))
        {
            return TEXT("Active");
        }
        else if (Subsystem->IsGameFeaturePluginRegistered(PluginURL))
        {
            return TEXT("Registered");
        }
        else if (Subsystem->IsGameFeaturePluginLoaded(PluginURL))
        {
            return TEXT("Loaded");
        }
        else if (Subsystem->IsGameFeaturePluginInstalled(PluginURL))
        {
            return TEXT("Installed");
        }
        else
        {
            return TEXT("Unknown");
        }
    }

    return FString();
}

void UGameFeatureBpLib::LoadGameFeature(UGameFeaturesSubsystem *Subsystem, const FString &InFeature)
{
    FString PluginURL;
    bool bOk = Subsystem->GetPluginURLByName(InFeature, PluginURL);
    if (bOk)
    {
        Subsystem->LoadGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete::CreateStatic(&UGameFeatureBpLib::OnStatus));
    }
}

void UGameFeatureBpLib::UnloadGameFeature(UGameFeaturesSubsystem *Subsystem, const FString &InFeature, bool bKeepRegistered)
{
    FString PluginURL;
    bool bOk = Subsystem->GetPluginURLByName(InFeature, PluginURL);
    if (bOk)
    {
        Subsystem->UnloadGameFeaturePlugin(PluginURL, bKeepRegistered);
    }
}

void UGameFeatureBpLib::ActivateGameFeature(UGameFeaturesSubsystem *Subsystem, const FString &InFeature)
{
    FString PluginURL;
    bool bOk = Subsystem->GetPluginURLByName(InFeature, PluginURL);
    if (bOk)
    {
        Subsystem->LoadAndActivateGameFeaturePlugin(PluginURL, FGameFeaturePluginLoadComplete::CreateStatic(&UGameFeatureBpLib::OnStatus));
    }
}

void UGameFeatureBpLib::DeactivateGameFeature(UGameFeaturesSubsystem *Subsystem, const FString &InFeature)
{
    FString PluginURL;
    bool bOk = Subsystem->GetPluginURLByName(InFeature, PluginURL);
    if (bOk)
    {
        Subsystem->DeactivateGameFeaturePlugin(PluginURL);
    }
}

void UGameFeatureBpLib::OnStatus(const UE::GameFeatures::FResult &InStatus)
{
    if (InStatus.HasValue() && InStatus.HasError())
    {
        UE_LOG(LogTemp, Error, TEXT("UGameFeatureBpLib OnStatus: %s"), *InStatus.GetError());
    }
}