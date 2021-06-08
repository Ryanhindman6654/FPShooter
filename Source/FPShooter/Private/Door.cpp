// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

ADoor::ADoor()
{
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetWorldScale3D(FVector(0.3, 2, 3));
	SetActorEnableCollision(true);
	// 문 텍스쳐 모델링 및 콜리전 설정
}

void ADoor::Open_Implementation() // IOpenable::Open 재정의
{
	AddActorLocalOffset(FVector(0, 0, 200)); // Open 함수 호출 시 액터(문)를 200 띄움
}

void ADoor::PerformInteract_Implementation() // 미구현
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("The door refuses to budge. Perhaps there is a hidden switch nearby?")); 
}