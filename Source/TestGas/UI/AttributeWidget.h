#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Blueprint/UserWidget.h"
#include "AttributeWidget.generated.h"

UCLASS()
class TESTGAS_API UAttributeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindToAttributes();

protected:
    UPROPERTY(BlueprintReadOnly)
	float HealthPercent;

	UPROPERTY(BlueprintReadOnly)
	float StaminaPercent;
};
