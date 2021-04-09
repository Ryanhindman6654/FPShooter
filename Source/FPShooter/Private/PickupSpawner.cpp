// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupSpawner.h"
#include "Pickup.h"

// Sets default values
APickupSpawner::APickupSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnLocation = CreateDefaultSubobject<USceneComponent>("SpawnLocation");
}

// Called when the game starts or when spawned
void APickupSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnPickup(); // 게임 시작 시 SpawnPickup() 실행
}

// Called every frame
void APickupSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupSpawner::PIckupCollected() // Pickup 액터가 BeginOverlap 시 델리게이트가 호출하는 함수다.
{
	CurrentPickup->OnPickedUp.Unbind(); // CurrentPickup 액터의 OnPickedUp 델리게이트를 언바인딩 (스폰된 액터로 인해 BeginOverlap되어 SpawnPickup()가 무한 호출되는걸 방지한다.)
	CurrentPickup->Destroy(); // 스폰된 CurrentPickup 액터를 파괴
	GetWorld()->GetTimerManager().SetTimer(MyTimer, this, &APickupSpawner::SpawnPickup, 5, false); // 5초 후 SpawnPickup 함수가 실행되도록 타이머 세팅
	/* 
		MyTimer는 이 클래스 하나에만 존재. Pickup 액터별로 존재하는게 아니다.
		그래서 위 2줄을 주석 처리해도 무조건 5초당 하나씩 하나의 액터만 생성된다. 
		(각 액터별로 PIckupCollected가 Execute 될 때마다 Spawner의 MyTimer가 초기화되기 때문 = 최종적으로 한 번만 작동된다.)
	*/
}

void APickupSpawner::SpawnPickup() // Pickup 액터를 스폰하는 함수
{
	if (GetWorld() != nullptr)
	{
		CurrentPickup = GetWorld()->SpawnActor<APickup>(APickup::StaticClass(), GetTransform()); // 현재 클래스의 위치에 월드에 액터<Pickup> 스폰
		CurrentPickup->OnPickedUp.BindUObject(this, &APickupSpawner::PIckupCollected); // 스폰한 액터(CurrentPickup)의 델리게이트에 PIckupCollected() 바인딩 
	}
}

/* 
	=== 구동 원리 ===
	
	1. 게임이 실행되면 Pickup 액터를 스폰하고 스폰한 액터의 델리게이트(OnPickedUp)에 PIckupCollected 함수를 바인딩한다.
	2. 스폰된 Pickup 액터는 다른 액터와 BeginOverlap이 일어나면 델리게이트를 Excute 하는데 현 클래스의 PIckupCollected()를 호출하게 된다.
	3. 바인딩된 함수가 호출되면 Pickup 액터를 파괴하고 5초 후 리스폰(SpawnPickup)한다. 
	4. 새로 스폰된 액터(Pickup)도 델리게이트에 PIckupCollected()를 바인딩해준다.


*/