#include "PlayerCharacter.h"
#include "AbilitySystem/MyAbilitySystemComponent.h"
#include "AbilitySystem/MyAttributeSet.h"
#include "Player/MyPlayerState.h"
#include "Helper.h"
#include "UI/MyHud.h"


APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;	
}

void APlayerCharacter::InitAbilitySystemComponent()
{
	AMyPlayerState *PS = GetPlayerState<AMyPlayerState>();
	check(PS);

	AbilitySystemComponent = CastChecked<UMyAbilitySystemComponent>(PS->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(PS, this);
}

void APlayerCharacter::InitHud()
{
	if (const APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (AMyHud* Hud = Cast<AMyHud>(PC->GetHUD()))
		{
			Hud->Init();
		}
	}
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
	InitHud();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
	InitDefaultAttributes();
}
