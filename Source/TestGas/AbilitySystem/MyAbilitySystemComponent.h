#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "MyAbilitySystemComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TESTGAS_API UMyAbilitySystemComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()
 
public:
    UMyAbilitySystemComponent();
    
protected:
    virtual void BeginPlay() override;
};
