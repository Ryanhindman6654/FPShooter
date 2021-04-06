// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeOfDayHandler.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnTimeChangedSignature, int32, int32) // 델리게이트 시그니처 생성(이름, 시간, 분) 

UCLASS()
class FPSHOOTER_API ATimeOfDayHandler : public AActor // 델리게이트를 선언하고 IF 문으로 델리게이터를 브로드캐스팅하는 조건을 지정한다.
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeOfDayHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FOnTimeChangedSignature OnTimeChanged; // 델리게이트

	UPROPERTY()
	int32 TimeScale; // 60프레임을 1초로 해서 계산한다. (시간 규모)

	UPROPERTY()
	int32 Hours; // 시

	UPROPERTY()
	int32 Minutes; // 분

	UPROPERTY()
	float ElapsedSeconds; // 경과한 시간(60초 간격)

};
