#include "MyCharacterBase.h"
#include "AbilitySystem/MyAbilitySystemComponent.h"

AMyCharacterBase::AMyCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* AMyCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMyAttributeSet* AMyCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AMyCharacterBase::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);

	if (!HasAuthority())
	{
		return;
	}

	for (const TSubclassOf<UGameplayAbility> Ability : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(Ability, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

void AMyCharacterBase::InitDefaultAttributes()
{
	if (!AbilitySystemComponent || !DefaultAttributeEffect)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);
	if (SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}
