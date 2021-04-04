// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "ParamDelegateListener.generated.h"

UCLASS()
class FPSHOOTER_API AParamDelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParamDelegateListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SetLightColor(FLinearColor LightColor); // 라이트 설정 함수

	UPROPERTY()
	class UPointLightComponent* PointLight; // 라이트 컴포넌트

	UPROPERTY()
	bool LightStats = true;
};
