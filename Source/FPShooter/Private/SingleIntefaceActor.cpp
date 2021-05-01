// Fill out your copyright notice in the Description page of Project Settings.


#include "SingleIntefaceActor.h"

// Sets default values
ASingleIntefaceActor::ASingleIntefaceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASingleIntefaceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASingleIntefaceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString ASingleIntefaceActor::GetTestName()
{
	// Super:: 사용안하는 이유는 Super는 부모의 UClass를 참조하기 때문에 (IInterface는 UClass가 아니다.) 스코프 연산자를 사용한다.
	return IMyInterface::GetTestName(); // 재정의한 가상 함수 
}

