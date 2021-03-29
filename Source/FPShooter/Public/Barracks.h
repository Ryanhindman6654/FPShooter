// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Barracks.generated.h"


UCLASS()
class FPSHOOTER_API ABarracks : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarracks();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UStaticMeshComponent* BulidingMesh;

	UPROPERTY()
	UParticleSystemComponent* SpawnPoint;

	UPROPERTY()
	UClass* UnitToSpawn; // 스폰할 유닛 객체

	UPROPERTY()
	float SpawnInterval; // 스폰 간격

	UFUNCTION()
	void SpawnUnit();

	UFUNCTION()
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override; // 액터 종료 시 호출되는 함수

	UPROPERTY()
	FTimerHandle SpawnTimerHandle;

};
