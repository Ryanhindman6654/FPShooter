// Fill out your copyright notice in the Description page of Project Settings.


#include "AntiGravityVolume.h"
#include "Components/BoxComponent.h"
#include "GravityObject.h"

// Sets default values
AAntiGravityVolume::AAntiGravityVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>("CollisionComponent");
	CollisionComponent->SetBoxExtent(FVector(200, 200, 400)); // 박스 컴포넌트로 충돌 영역 설정
	RootComponent = CollisionComponent; // 이 액터는 이제 콜리전 컴포넌트가 대표다.
}

// Called when the game starts or when spawned
void AAntiGravityVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAntiGravityVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAntiGravityVolume::NotifyActorBeginOverlap(AActor* OtherActor) // 액터와 겹쳐질 경우
{
	IGravityObject* GravityObject = Cast<IGravityObject>(OtherActor); // 대상 액터를 그레비티 인터페이스로 캐스팅(인터페이스 함수를 호출하기 위해)
	// 여기서 인터페이스의 장점이 두드러지는데 대상 액터의 이름과 정보를 알 필요 없이, 인터페이스 정보만을 가지고도 대상 액터를 조작할 수 있다. (상속된 인터페이스 함수를 호출하여)
	if (GravityObject != nullptr)
	{
		GravityObject->DisableGravity(); // 액터의 인터페이스 Disable 함수를 호출
	}
}

void AAntiGravityVolume::NotifyActorEndOverlap(AActor* OtherActor) // 액터와 겹침이 끝날 경우
{
	IGravityObject* GravityObject = Cast<IGravityObject>(OtherActor);
	if (GravityObject != nullptr)
	{
		GravityObject->EnableGravity(); // 액터의 인터페이스 Enable 함수를 호출
	}
}

