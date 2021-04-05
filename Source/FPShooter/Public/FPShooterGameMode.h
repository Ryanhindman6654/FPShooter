// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPShooterGameMode.generated.h"

// 델리게이트 시그니처 선언
DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDynamicDelegateSignature);
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)

 UCLASS(minimalapi)
class AFPShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// 시그니처를 토대로 델리게이트 선언
	FParamDelegateSignature MyParameterDelegate;
	FDynamicDelegateSignature MyDynamicMulticastDelegateSignature;

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



