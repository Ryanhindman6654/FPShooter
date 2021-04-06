// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "Clock.generated.h"

UCLASS()
class FPSHOOTER_API AClock : public AActor // 델리게이트에 영향을 받는 리스너다. (시계 초침) 
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class USceneComponent* RootScenceComponent;

	UPROPERTY()
	class UStaticMeshComponent* ClockFace; // 시계 배경(판)

	UPROPERTY()
	USceneComponent* HourHandle;

	UPROPERTY()
	UStaticMeshComponent* HourHand; // 시 초침

	UPROPERTY()
	USceneComponent* MinuteHandle;

	UPROPERTY()
	UStaticMeshComponent* MinuteHand; // 분 초침

	UFUNCTION()
	void TimeChaned(int32 Hours, int32 Minutes);

	FDelegateHandle MyDelegateHandle; // 현재 델리게이트에 몇 개의 함수가 바인딩되었는지 표시용

};
