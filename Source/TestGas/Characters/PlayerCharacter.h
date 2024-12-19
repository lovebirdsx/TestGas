// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacterBase.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TESTGAS_API APlayerCharacter : public AMyCharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	void InitAbilitySystemComponent();
};
