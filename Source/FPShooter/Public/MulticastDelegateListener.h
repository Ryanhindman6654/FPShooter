// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MulticastDelegateListener.generated.h"

UCLASS()
class FPSHOOTER_API AMulticastDelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMulticastDelegateListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FDelegateHandle MyDelegateHandle; // 델리게이트 핸들은 델리게이트가 어떤 함수를 바인딩했는지 저장하기 위한 객체다.

	UFUNCTION()
	void ToggleLight();

	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY()
	class UPointLightComponent* PointLight;

	UPROPERTY()
	bool LightStats = true;
};
