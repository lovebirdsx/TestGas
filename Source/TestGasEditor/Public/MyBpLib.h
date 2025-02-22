#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBpLib.generated.h"

UCLASS(Blueprintable)
class TESTGASEDITOR_API UMyBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "TestUe")
	static FString GetPackageName(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "TestUe")
	static void StartAutomationTest();	
	
	UFUNCTION(BlueprintCallable, Category = "TestUe")
	static void StartTestByPrefix(const FString& Prefix);

	UFUNCTION(BlueprintCallable, Category = "TestUe")
	static void StartLiveCodingCompile();

	UFUNCTION(BlueprintCallable, Category = "TestUe")
	static void ShowSessionFrontend();
	
	UFUNCTION(BlueprintCallable, Category = "TestUe")
	static void UnloadSelectedAssets();

	UFUNCTION(BlueprintCallable, Category = "TestUe")
	static void LoadSelectedAssets();

	UFUNCTION(BlueprintCallable, Category = "TestUe")
	static void ShowSelectedAssetsLoadInfo();	
};
