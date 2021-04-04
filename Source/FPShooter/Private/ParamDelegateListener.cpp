// Fill out your copyright notice in the Description page of Project Settings.

#include "ParamDelegateListener.h"
#include "FPShooterGameMode.h"
#include "Components/PointLightComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AParamDelegateListener::AParamDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight"); // 라이트 컴포넌트 인스턴스화
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void AParamDelegateListener::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode); // GetWorld의 Gamemode를 가져옴 <AFPShooterGameMode>로 다운 캐스팅
		if (MyGameMode != nullptr)
		{
			MyGameMode->MyParameterDelegate.BindUObject(this, &AParamDelegateListener::SetLightColor); // 델리게이트에 SetLightColor() 바인딩
		}
	}
	
}

// Called every frame
void AParamDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AParamDelegateListener::SetLightColor(FLinearColor LightColor)
{
	PointLight->SetVisibility(LightStats);
	PointLight->SetLightColor(LightColor); // RGB 값으로 라이트 색상 설정
	LightStats = !LightStats;
}
