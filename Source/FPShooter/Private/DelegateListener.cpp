// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateListener.h"
#include "GameFramework/Actor.h"
#include "FPShooterGameMode.h"
#include "Kismet/GameplayStatics.h"

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
			MyGameMode->MyDynamicMulticastDelegateSignature.AddDynamic(this, &ADelegateListener::FuncA); // My~Delegate 델리게이트에 EnableLight 함수 바인딩
			MyGameMode->MyDynamicMulticastDelegateSignature.AddDynamic(this, &ADelegateListener::EnableLight);
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
		AFPShooterGameMode* MyGameMode = (AFPShooterGameMode*)GameMode; // 또는 이렇게도 캐스팅 가능하다.
		if (MyGameMode != nullptr)
		{
			if (MyGameMode->MyDynamicMulticastDelegateSignature.IsBound())
			{
				// MyGameMode->MyStandardDelegate.Unbind(); 델리게이트 언바인딩 (MyStandardDelegate에 연결된 함수(EnableLight)를 해제함)
				// 이를 통해 DelegateListener 액터가 게임을 떠날 때 게임모드의 MyStandardDelegate 포인터가 댕글링 포인터가 되지 않도록 예방할 수 있다.
				MyGameMode->MyDynamicMulticastDelegateSignature.Clear(); // 델리게이트 언바인딩
				GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Exit")));
			}
		}
	}
}

void ADelegateListener::FuncA()
{
	GEngine->AddOnScreenDebugMessage(7, 3.0f, FColor::Blue, TEXT("I'm FuncA Call"));
}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(LightStats);
	LightStats = !LightStats;
}
