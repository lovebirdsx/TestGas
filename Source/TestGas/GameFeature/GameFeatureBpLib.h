#pragma once

#include "CoreMinimal.h"
#include "GameFeaturesSubsystem.h"
#include "GameFeatureBpLib.generated.h"

UCLASS()
class TESTGAS_API UGameFeatureBpLib : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    static FString GetGameFeatureStatus(class UGameFeaturesSubsystem *Subsystem, const FString &InFeature);

    UFUNCTION(BlueprintCallable)
    static void LoadGameFeature(class UGameFeaturesSubsystem *Subsystem, const FString &InFeature);

    UFUNCTION(BlueprintCallable)
    static void UnloadGameFeature(class UGameFeaturesSubsystem *Subsystem, const FString &InFeature, bool bKeepRegistered = false);

    UFUNCTION(BlueprintCallable)
    static void ActivateGameFeature(class UGameFeaturesSubsystem *Subsystem, const FString &InFeature);

    UFUNCTION(BlueprintCallable)
    static void DeactivateGameFeature(class UGameFeaturesSubsystem *Subsystem, const FString &InFeature);

private:
    static void OnStatus(const UE::GameFeatures::FResult &InStatus);
};
