// Fill out your copyright notice in the Description page of Project Settings.


#include "UserProfile.h"

UUserProfile::UUserProfile()
{
	Armor = 45.0f;
	HpMax = 30.0f;
	Name = "Tex";

	TArray<FStringFormatArg> args;
	args.Add(FStringFormatArg(Armor));
	args.Add(FStringFormatArg(Name));
	FString string = FString::Format(TEXT("Name = {0}, Mana = {1}"), args);
	UE_LOG(LogTemp, Warning, TEXT("%s %s"), *FP_LOG_CALLINFO, *string);
}

