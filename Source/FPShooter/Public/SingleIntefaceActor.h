// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "SingleIntefaceActor.generated.h"

UCLASS()
class FPSHOOTER_API ASingleIntefaceActor : public AActor, public IMyInterface // (액터에서 상속받을 땐 구현부의)IMyInterface 인터페이스를 상속받았다.
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASingleIntefaceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString GetTestName() override; // 인터페이스의 가상 함수를 재정의해준다.
};
