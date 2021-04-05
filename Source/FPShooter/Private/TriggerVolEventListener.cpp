// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolEventListener.h"
#include "Components/PointLightComponent.h"
#include "MyTriggerVolume.h"

// Sets default values
ATriggerVolEventListener::ATriggerVolEventListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLihgt");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void ATriggerVolEventListener::BeginPlay()
{
	Super::BeginPlay();
	
	if (TriggerEventSource != nullptr) // 델리게이트와 달리 게임모드를 거치지 않고 바로 이벤트를 사용할 클래스(MyTriggerVolume)를 불러와서 바인딩한다. (액터 지정은 에디터에서 한다)
	{
		TriggerEventSource->OnPlayerEntered.AddUObject(this, &ATriggerVolEventListener::OnTriggerEvent); // 이벤트가 선언된 클래스에 OnTriggerEvent()를 바인딩
	}
}

// Called every frame
void ATriggerVolEventListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerVolEventListener::OnTriggerEvent()
{
	PointLight->SetLightColor(FLinearColor(0, 1, 0, 1));
	PointLight->SetVisibility(LightStats);
	LightStats = !LightStats;
}

