// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameState.h"

AFPSGameState::AFPSGameState()
{
	CurrentState = 0;
}

void AFPSGameState::SetScore(int32 NewScore)
{
	CurrentState = NewScore;
}

int AFPSGameState::GetScore()
{
	return CurrentState;
}
