	// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBell.h"
#include "Openable.h"

ADoorBell::ADoorBell()
{
	HasBeenPushed = false;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	
	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetWorldScale3D(FVector(0.5, 0.5, 0.5));
	SetActorEnableCollision(true); // 벨 텍스처 모델링 및 콜리전 설정
	DoorToOpen = nullptr; // 벨이 담당하는 문의 주소는 레벨에서 설정해준다.
}

bool ADoorBell::CanInteract_Implementation()
{
	return !HasBeenPushed; // 벨이 이미 눌린지 안 눌린지 상태 값 반환
}

void ADoorBell::PerformInteract_Implementation()
{
	HasBeenPushed = true; // 벨 상태 값을 true로 변환
	// 특정 클래스에 특정 인터페이스가 구현되어있는지 여부를 확인하려면(리플랙션) ImplementsInterface 함수를 쓰면 된다.
	// DoorToOpen 액터가 UOpenable 인터페이스를 상속받았을 경우 true가 반환된다.
	if (DoorToOpen->GetClass()->ImplementsInterface(UOpenable::StaticClass()))
	{
		IOpenable::Execute_Open(DoorToOpen); // DoorToOpen(문) 액터의 Open 인터페이스 함수를 실행 (문을 연다)
	}
}
