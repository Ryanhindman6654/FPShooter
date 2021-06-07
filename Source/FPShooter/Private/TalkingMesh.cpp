// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingMesh.h"

ATalkingMesh::ATalkingMesh()
{
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
		GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
		SetActorEnableCollision(true); // 메시 스킨 설정 및 콜리전 지정
	}
}

void ATalkingMesh::StartTalking_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Hello there, What is your name?")); // 인터페이스 StartTalking 함수 재정의
}


