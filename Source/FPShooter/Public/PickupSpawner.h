// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupSpawner.generated.h"

UCLASS()
class FPSHOOTER_API APickupSpawner : public AActor // Pikckup 액터용 스포너
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	USceneComponent* SpawnLocation; // Pickup 액터의 스폰 지점

	UFUNCTION()
	void PIckupCollected();

	UFUNCTION()
	void SpawnPickup();

	UPROPERTY()
	class APickup * CurrentPickup; // 스폰할 액터

	FTimerHandle MyTimer; // 타이머 세팅하기 위한 핸들
};
