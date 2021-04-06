// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeOfDayHandler.h"

// Sets default values
ATimeOfDayHandler::ATimeOfDayHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TimeScale = 60;
	Hours = 0;
	Minutes = 0;
	ElapsedSeconds = 0;

}

// Called when the game starts or when spawned
void ATimeOfDayHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// 델리게이트 브로드캐스트 조건 지정
void ATimeOfDayHandler::Tick(float DeltaTime) // 매 프레임 별
{
	Super::Tick(DeltaTime);

	ElapsedSeconds += (DeltaTime * TimeScale); // 60프레임이 될 때까지 계산하고
	if (ElapsedSeconds > 60) // 60프레임이 될 경우 Broadcast 한다.
	{
		ElapsedSeconds -= 60; // 60을 0으로 초기화
		Minutes++; // 1초당 1분이 지나가는 방식
		if (Minutes >= 60) // 60분이 넘으면
		{
			Minutes -= 60; // 분을 초기화하고
			Hours++; // 시를 증가시킨다. 
		}
		OnTimeChanged.Broadcast(Hours, Minutes); // 60프레임 마다(=1초) 시간과 분을 파라미터로 받아서 Broadcast 한다. (바인딩 함수 실행)
	}
}

