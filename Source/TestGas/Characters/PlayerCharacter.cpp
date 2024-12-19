#include "PlayerCharacter.h"
#include "AbilitySystem/MyAbilitySystemComponent.h"
#include "AbilitySystem/MyAttributeSet.h"
#include "Player/MyPlayerState.h"
#include "Helper.h"


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

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
	InitDefaultAttributes();
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	PRINT("Hello, %s", *FString(__FUNCTION__));

	const FVector TargetLocation(1745, 600, 200);
	DrawSphere(GetWorld(), TargetLocation);	
}

void APlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	const FVector TargetLocation(1745, 600, 400);
	DrawSphereTick(GetWorld(), TargetLocation);
	DrawLineTick(GetWorld(), GetActorLocation(), TargetLocation);
}
