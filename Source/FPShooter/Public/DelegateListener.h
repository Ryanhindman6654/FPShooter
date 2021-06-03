// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DelegateListener.generated.h"

UCLASS()
class FPSHOOTER_API ADelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY()
	bool LightStats = true;

	UFUNCTION()
	void EnableLight(); // 바인딩할 함수1

	UFUNCTION()
	void FuncA(); // 바인딩할 함수2

	UPROPERTY()
	class UPointLightComponent* PointLight;

	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;



};
