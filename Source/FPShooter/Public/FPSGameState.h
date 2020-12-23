// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPSGameState.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API AFPSGameState : public AGameStateBase
{
	GENERATED_BODY()
	

public:
	AFPSGameState();

	UFUNCTION()
	void SetScore(int32 NewScore);

	UFUNCTION()
	int GetScore();

private:
	UPROPERTY()
	int32 CurrentState;
};
