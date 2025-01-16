#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TeleportConfig.generated.h"

UCLASS()
class TESTGAS_API UTeleportConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=TestGas, meta=(AllowedTypes="Map"))
	FPrimaryAssetId MapID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=TestGas, meta=(AllowedTypes="Map"))
	TSoftObjectPtr<UWorld> World;
};
