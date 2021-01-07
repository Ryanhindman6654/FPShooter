// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingMovementComponent.h"

// Sets default values for this component's properties
UOrbitingMovementComponent::UOrbitingMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	RotationSpeed = 20;  // 매 초마다 컴포넌트가 회전하는 각도
	OrbitDistance = 100; // 컴포넌트가 원점에서 움직이기 위해 회전해야 하는 거리
	CurrentValue = 0; // 현재 각도에서 회전 위치
	RotateToFaceOutwards = true; // 공전 유무
	
}


// Called when the game starts
void UOrbitingMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{ 
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float CurrentValueInRadinas = FMath::DegreesToRadians<float>(CurrentValue); // CurentValue를 디그리 각도에서 라디안 각도로 바꾼다.
	SetRelativeLocation(FVector(OrbitDistance *
		FMath::Cos(CurrentValueInRadinas), OrbitDistance *
		FMath::Sin(CurrentValueInRadinas), GetRelativeLocation().Z)); // 회전 위치를 계산
	if (RotateToFaceOutwards)
	{
		FVector LookDir = (GetRelativeLocation()).GetSafeNormal();
		FRotator LookAtRot = LookDir.Rotation();
		SetRelativeRotation(LookAtRot); // 회전 각도를 계산
	}
	CurrentValue = FMath::Fmod(CurrentValue + (RotationSpeed * DeltaTime), 360);
}

