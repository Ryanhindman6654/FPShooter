// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("MyMesh");
	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingComponent");
	RootComponent = MyMesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		MyMesh->SetStaticMesh(MeshAsset.Object); // 액터 스킨 지정
	}

	MyMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic")); // 콜리전 설정
	RotatingComponent->RotationRate = FRotator(10, 0, 10); // 회전 방향 및 속도 설정

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	OnPickedUp.ExecuteIfBound(); // 다른 액터와 겹쳐질 경우 OnPickedUp 델리게이트에 바인딩한 함수 호출
}

