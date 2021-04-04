// Fill out your copyright notice in the Description page of Project Settings.


#include "Barracks.h"
#include "BarracksUnit.h"

// Sets default values
ABarracks::ABarracks()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulidingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BulidingMesh");
	SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");
	SpawnInterval = 5; // 스폰 간격

	// 배럭 스킨
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Succeeded())
	{
		BulidingMesh->SetStaticMesh(MeshAsset.Object);
		BulidingMesh->SetCollisionProfileName(FName(TEXT("Pawn"))); // 콜리전(충돌영역) 설정
	}

	// 스폰 지점 표시용
	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (ParticleSystem.Succeeded())
	{
		SpawnPoint->SetTemplate(ParticleSystem.Object);
	}

	RootComponent = BulidingMesh;
	SpawnPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform); // 스폰 포인트를 루트(메시)에 상속
	SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5)); // 스폰 포인트의 스케일 설정

	UnitToSpawn = ABarracksUnit::StaticClass(); // 스폰유닛 객체 지정
}

// Called when the game starts or when spawned
void ABarracks::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABarracks::SpawnUnit, SpawnInterval, true); // 5초 마다 유닛 스폰
}

// Called every frame
void ABarracks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarracks::SpawnUnit() // 유닛 스폰 함수
{
	FVector SpawnLocation = SpawnPoint->GetComponentLocation() + FVector(50, 0, 0); // 스폰 포인트의 좌표
	GetWorld()->SpawnActor(UnitToSpawn, &SpawnLocation); // 해당 위치에 UnitToSpawn 객체 생성
}

void ABarracks::EndPlay(const EEndPlayReason::Type EndPlayReason) // 액터 종료시 호출되는 함수
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle); // 부모 클래스가 파괴될 때 스폰 타이머를 해제(유효하지 않음)
}

