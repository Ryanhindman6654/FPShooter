// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMovementComponent.h"

// Sets default values for this component's properties
URandomMovementComponent::URandomMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MovementRadius = 5; // 위치 이동 시 비중치 설정 
}


// Called when the game starts
void URandomMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame 틱 별 함수 호출
void URandomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Parent = GetOwner(); // 액터 컴포넌트의 현 액터
	if (Parent)
	{	// SetActorLoc = 액터의 위치 설정
		Parent->SetActorLocation(Parent->GetActorLocation() + // 현재 위치 값에다 새로운 위치값(vec)을 더해서(+) 액터를 현재 위치에서 다른 위치로 이동 
			FVector(
				FMath::FRandRange(-1, 1) * MovementRadius, // XYZ 간격
				FMath::FRandRange(-1, 1) * MovementRadius,
				FMath::FRandRange(-1, 1) * MovementRadius));
	}
}

