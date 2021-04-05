// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerVolEventListener.generated.h"

UCLASS()
class FPSHOOTER_API ATriggerVolEventListener : public AActor // 이벤트에 영향 받을 액터
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerVolEventListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class UPointLightComponent * PointLight;

	UPROPERTY(EditAnywhere) // 이벤트를 호출하는 액터의 지정은 에디터에서 설정
	class AMyTriggerVolume* TriggerEventSource; // 바인딩을 위해 이벤트를 호출하는 클래스를 가져왔다. 

	UFUNCTION()
	void OnTriggerEvent();

	UPROPERTY()
	bool LightStats = true;

};
