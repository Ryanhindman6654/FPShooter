// Fill out your copyright notice in the Description page of Project Settings.


#include "PostBeginPlay.h"

// Add default functionality here for any IPostBeginPlay functions that are not pure virtual.

void IPostBeginPlay::OnPostBeginPlay() // PostBeginPlayTest1 액터가 레벨 블루프린트에서 호출할 인터페이스 함수
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "PostBeginPlaycalled");
}







