// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMovementComponent.h"

// Sets default values for this component's properties
URandomMovementComponent::URandomMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MovementRadius = 5; // ��ġ �̵� �� ����ġ ���� 
}


// Called when the game starts
void URandomMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame ƽ �� �Լ� ȣ��
void URandomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* Parent = GetOwner(); // ���� ������Ʈ�� �� ����
	if (Parent)
	{
		Parent->SetActorLocation(Parent->GetActorLocation() + // ���͸� ���� ��ġ���� �ٸ� ��ġ�� �̵� 
			FVector(
				FMath::FRandRange(-1, 1) * MovementRadius, // XYZ ����
				FMath::FRandRange(-1, 1) * MovementRadius, 
				FMath::FRandRange(-1, 1) * MovementRadius));
	}
}
