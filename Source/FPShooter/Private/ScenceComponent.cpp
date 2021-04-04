// Fill out your copyright notice in the Description page of Project Settings.


#include "ScenceComponent.h"
#include "HierachyActor.h"

// Sets default values for this component's properties
UScenceComponent::UScenceComponent() // 씬 컴포넌트 : 트랜스폼을 가진 액터 컴포넌트
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UScenceComponent::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
	// ...

}


// Called every frame
void UScenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UScenceComponent::Spawn()
{
	UWorld* TheWorld = GetWorld(); // 월드 객체(액터를 스폰 시키기 위한)
	if (TheWorld != nullptr)
	{
		FTransform ComponentTransform(this->GetComponentTransform()); // 현 컴포넌트의 좌표(※ 씬 컴포넌트는 좌표를 가질 수 있다.)
		TheWorld->SpawnActor(ActorToSpawn, &ComponentTransform); // HierachyActor 액터를 부모 클래스 ScenceCompoent의 좌표에 스폰시킨다.
	}
}

