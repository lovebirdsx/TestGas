#include "MyAbilitySystemComponent.h"

UMyAbilitySystemComponent::UMyAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}

void UMyAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}
