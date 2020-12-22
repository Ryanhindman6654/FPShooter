// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPShooterGameMode.h"
#include "FPShooterHUD.h"
#include "FPShooterCharacter.h"
#include "UserProfile.h"
#include "MyFirstActor.h"
#include "CustomStruct.h"
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

	FColoredTexture texture;
	TEnumAsByte<Status> status = Status::Attacking;

	UUserProfile* action = NewObject<UUserProfile>(GetTransientPackage(), UUserProfile::StaticClass());
	UObject* oz = 0;

}

void AFPShooterGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);


}

void AFPShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	FTransform SpawnLocation;

	GEngine->AddOnScreenDebugMessage(7, 3.0f, FColor::Blue, TEXT("Actor Spawning"));
	SpawnedActor =  GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLocation);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AFPShooterGameMode::DestroyActorFunction, 10); // 10초 후에 엑터 제거
}

void AFPShooterGameMode::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		SpawnedActor->Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, TEXT("Actor Destroyed"));
		UE_LOG(LogTemp, Error, TEXT("%s : SpawnedActor Destroyed"), *FP_LOG_CALLINFO);
	}
}
