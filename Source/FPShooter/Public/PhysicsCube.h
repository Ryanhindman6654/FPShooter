// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GravityObject.h"
#include "PhysicsCube.generated.h"

UCLASS()
class FPSHOOTER_API APhysicsCube : public AActor, public IGravityObject // 인터페이스를 상속받아 AntiGravityVolume 트리거 존에서 이 액터의 인터페이스 함수를 호출하여 액터를 조작할 수 있게 한다. 
{																		// AntiGravityVolume은 OtherActor가 GravityObject 인터페이스를 가지고 있다는 것 외에는 해당 액터의 이름과 정체를 알 필요도 없다. (결합도 최소화)
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicsCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UStaticMeshComponent* MyMesh; // 스킨

	virtual void EnableGravity() override; // 인터페이스 함수를 재정의 (액터별로 필요한 추가 요소가 있을 경우 이렇게 인터페이스의 가상 함수를 재정의해준다.)
};
