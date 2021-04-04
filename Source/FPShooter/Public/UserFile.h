// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserFile.generated.h" // generated.h 파일은 반드시 include 목록의 마지막에 위치해야 한다.

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FPSHOOTER_API UUserFile : public UObject
{
	GENERATED_BODY()
	
public:
	UUserFile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float HpMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	TSubclassOf<UObject> UClassOfPlayer;

	// GameMode C++ base class
	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"), Category = Unit)
	FStringClassReference UClassGameMode;

};
	