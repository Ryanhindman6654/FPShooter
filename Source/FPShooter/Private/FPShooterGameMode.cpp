// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPShooterGameMode.h"
#include "FPShooterHUD.h"
#include "FPShooterCharacter.h"
#include "UserProfile.h"
#include "CustomStruct.h"
#include "MyFirstActor.h"
#include "UObject/ConstructorHelpers.h"

AFPShooterGameMode::AFPShooterGameMode() : Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPShooterHUD::StaticClass();
}

void AFPShooterGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AFPShooterGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void AFPShooterGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTransform SpawnLocation = FTransform(FVector(-450.0f, 150.0f, 150.0f)); // 스폰 지점 설정
	FTimerHandle Timer;

	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLocation); // SpawnLocation 지점에 액터룰 생성한 후 생성된 액터 주소를 반환함
	GetWorldTimerManager().SetTimer(Timer, this, &AFPShooterGameMode::DestroyActorFunction, 5); // 5초간 타이머 후 DestroyActorFunction() 핸들링
	GEngine->AddOnScreenDebugMessage(7, 3.0f, FColor::Green, TEXT("Hierachy Actor Spawning.")); // UI에 로그 기록
}

void AFPShooterGameMode::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		SpawnedActor->Destroy(); // 스폰된 액터 삭제
	}
}