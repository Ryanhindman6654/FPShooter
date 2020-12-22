// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPShooterGameMode.generated.h"

UCLASS(minimalapi)
class AFPShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNames)
	TSubclassOf<class UUserProfile> UPBlueprintClassName;

	AFPShooterGameMode();
	virtual void PostInitializeComponents() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
	void BeginPlay() override;

	UPROPERTY()
	class AMyFirstActor * SpawnedActor;

	UFUNCTION()
	void DestroyActorFunction();

};



