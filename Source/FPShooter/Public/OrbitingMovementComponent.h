// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "OrbitingMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSHOOTER_API UOrbitingMovementComponent : public USceneComponent // 궤도 시스템 컴포넌트
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrbitingMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	bool RotateToFaceOutwards; // 매 틱마다 회전의 중앙을 모주볼지 여부

	UPROPERTY()
	float RotationSpeed; // 매 초마다 컴포넌트가 회전하는 각도

	UPROPERTY()
	float OrbitDistance; // 컴포넌트가 원점에서 움직이기 위해 회전해야 하는 거리
	float CurrentValue; // 현재 각도에서 회전 위치

		
};
