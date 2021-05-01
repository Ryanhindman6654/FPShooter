// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPShooterGameMode.h"
#include "FPShooterHUD.h"
#include "FPShooterCharacter.h"
#include "UserProfile.h"
#include "CustomStruct.h"
#include "MyFirstActor.h"
#include "SingleIntefaceActor.h"
#include "MyInterface.h"
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

	ASingleIntefaceActor* SpawnedInterfaceActor = GetWorld()->SpawnActor<ASingleIntefaceActor>(ASingleIntefaceActor::StaticClass(), SpawnLocation); // 인터페이스가 상속된 SingleActor를 Location에 스폰하고 주소를 저장한다.
	if (SpawnedInterfaceActor->GetClass()->ImplementsInterface(UMyInterface::StaticClass())) 
		/* 
			액터의ImplementsInterface()를 통해 객체가 정확한 인터페이스를 가지고 있다면 true를 반환한다.
			UMyInterface는 IMyInterface의 원형이고 UClass이기도 해서 리플렉션 데이터로 반환할 수 있기에 객체에서 바로 MyInterface를 찾을 수 있다.
		 */
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Spawned actor implements interface!")); // UI에 확인 로그를 기록한다.
	}
	
}

void AFPShooterGameMode::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		SpawnedActor->Destroy(); // 스폰된 액터 삭제
	}
}

