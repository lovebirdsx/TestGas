#include "AttributeWidget.h"
#include "AbilitySystem/MyAttributeSet.h"
#include "Player/MyPlayerState.h"

void UAttributeWidget::BindToAttributes()
{
	const AMyPlayerState* PS = GetOwningPlayerState<AMyPlayerState>();
	if (!PS)
	{
		return;
	}

	UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
	const UMyAttributeSet* AttributeSet = PS->GetAttributeSet();

	HealthPercent = AttributeSet->GetHealth() / AttributeSet->GetMaxHealth();
	StaminaPercent = AttributeSet->GetStamina() / AttributeSet->GetMaxStamina();

	ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddLambda(
		[this, AttributeSet](const FOnAttributeChangeData& Data)
		{
			HealthPercent = Data.NewValue / AttributeSet->GetMaxHealth();
		}
	);

	ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStaminaAttribute()).AddLambda(
		[this, AttributeSet](const FOnAttributeChangeData& Data)
		{
			StaminaPercent = Data.NewValue / AttributeSet->GetMaxStamina();
		}
	);
}
