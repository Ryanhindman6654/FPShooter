// Fill out your copyright notice in the Description page of Project Settings.


#include "MulticastDelegateListener.h"
#include "Components/PointLightComponent.h"
#include "FPShooterGamemode.h"


// Sets default values
AMulticastDelegateListener::AMulticastDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLihgt");
	RootComponent = PointLight;
	PointLight->ToggleVisibility(false);
}

// Called when the game starts or when spawned
void AMulticastDelegateListener::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);

		if (MyGameMode != nullptr)
		{
			MyDelegateHandle = MyGameMode->MyMulticastDelegate.AddUObject(this, &AMulticastDelegateListener::ToggleLight); // 델리게이트 핸들에 바인딩하고난 반환 값을 지정해야 한다. (리무브시 사용)
		}
	}
}

// Called every frame
void AMulticastDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMulticastDelegateListener::ToggleLight()
{
	PointLight->ToggleVisibility(LightStats);
	LightStats = !LightStats;
}

void AMulticastDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);

		if (MyGameMode != nullptr)
		{
			MyGameMode->MyMulticastDelegate.Remove(MyDelegateHandle); // 저장된 델리게이트 핸들을 Remove()에 대한 파라미터로 사용하여 델리게이트에 바인딩된 함수 목록을 안전하게 제거한다.
		}
	}
}

