// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateListener.h"
#include "FPShooterGameMode.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight); // MyStandardDelegate 델리게이트에 EnableLight 함수 바인딩
		}
	}
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyStandardDelegate.Unbind(); // 델리게이트를 언바인딩. MyStandardDelegate에 연결된 함수(EnableLight)를 해제함
			// 이를 통해 DelegateListener 액터가 게임을 떠날 때 게임모드의 MyStandardDelegate 포인터가 댕글링 포인터가 되지 않도록 예방할 수 있다.
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Exit")));
		}
	}
}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(LightStats);
	LightStats = !LightStats;
}
