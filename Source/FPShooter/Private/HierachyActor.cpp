// Fill out your copyright notice in the Description page of Project Settings.


#include "HierachyActor.h"

// Sets default values
AHierachyActor::AHierachyActor() // 계층 구조를 지니는 액터
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 정의
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	ChildScenceComponent = CreateDefaultSubobject<USceneComponent>("ChildScenceComponent");
	BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

	// 컴포넌트에 메쉬 붙이기
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	if (MeshAsset.Succeeded())
	{
		BoxOne->SetStaticMesh(MeshAsset.Object); // boxOne과 boxTwo 모두 원뿔형 메시를 가진다.
		BoxTwo->SetStaticMesh(MeshAsset.Object);
	}

	// 계층구조 생성
	RootComponent = Root;
	BoxOne->AttachTo(Root);
	BoxTwo->AttachTo(ChildScenceComponent);
	ChildScenceComponent->AttachTo(Root);
	ChildScenceComponent->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(250, 0, 0), FVector(0.1f))); // 회전, 좌표, 스케일 설정
}

// Called when the game starts or when spawned
void AHierachyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierachyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

