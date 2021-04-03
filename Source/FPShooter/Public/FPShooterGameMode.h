// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPShooterGameMode.generated.h"

DECLARE_DELEGATE(FStandardDelegateSignature)

UCLASS(minimalapi)
class AFPShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	FStandardDelegateSignature MyStandardDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNames)
	TSubclassOf<class UUserProfile> UPBlueprintClassName;

	AFPShooterGameMode();
	virtual void PostInitializeComponents() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
	void BeginPlay() override;

	UPROPERTY()
	class AMyFirstActor * SpawnedActor; // 스폰할 액터 주소 포인터

	UFUNCTION()
	void DestroyActorFunction(); // 스폰한 액터 삭제 함수
};



