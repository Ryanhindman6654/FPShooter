// Fill out your copyright notice in the Description page of Project Settings.


#include "BarracksUnit.h"

// Sets default values
ABarracksUnit::ABarracksUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualRepresentation = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint"); // 스폰 유닛(파티클)
	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (ParticleSystem.Succeeded())
	{
		VisualRepresentation->SetTemplate(ParticleSystem.Object);
	}
	VisualRepresentation->SetRelativeScale3D(FVector(3.0, 3.0, 3.0)); // 파티클의 스케일 지정
	VisualRepresentation->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform); // 생성한 파티클을 액터(스폰 캐릭터)에 상속시킴(같은 좌표를 가지게)
	// 주의사항 : 상속 타이밍을 BeginPlay로 설정하면 파티클이 맵 중앙에 생성되고 나서 상속되기에(루트에 붙여지기에) 미리 생성자에서 상속 구조를 처리해준다.
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; // 스폰할 지점에 가로막는게 있을 경우 어떻게 할지 설정(무시하고 스폰)
	
}

// Called when the game starts or when spawned
void ABarracksUnit::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABarracksUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + FVector(15, 0, -0.1)); // 스폰한 유닛이 매 프레임마다 10만큼 전진
}

// Called to bind functionality to input
void ABarracksUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

