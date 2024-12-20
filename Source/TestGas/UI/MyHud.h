#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHud.generated.h"

class UAttributeWidget;

UCLASS()
class TESTGAS_API AMyHud : public AHUD
{
	GENERATED_BODY()

public:
	void Init();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAttributeWidget> AttributeWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UAttributeWidget> AttributeWidget;
};
