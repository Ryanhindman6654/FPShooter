// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPShooterGameMode.h"
#include "FPShooterHUD.h"
#include "FPShooterCharacter.h"
#include "UserProfile.h"
#include "CustomStruct.h"
#include "MyFirstActor.h"
#include "InventoryComponent.h"
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

	FTransform SpawnLocation = FTransform(FVector(-450.0f, 150.0f, 150.0f));
	FTimerHandle Timer;

	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLocation); // 액터 생성
	GetWorldTimerManager().SetTimer(Timer, this, &AFPShooterGameMode::DestroyActorFunction, 5); // 5초후 액터 삭제
	GEngine->AddOnScreenDebugMessage(7, 3.0f, FColor::Blue, TEXT("Actor Spawning")); // 게임화면에 로그 기록
}

void AFPShooterGameMode::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		SpawnedActor->Destroy();
	}
}

int32 AFPShooterGameMode::AddtoInventory(AInventoryActor* ActorToAdd)
{
	return CurrentInventory.Add(ActorToAdd);
}

void AFPShooterGameMode::RemoveFromInventory(AInventoryActor* ActorToRemove)
{
	CurrentInventory.Remove(ActorToRemove);
}


