// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "Talker.h"
#include "TalkingPawn.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API ATalkingPawn : public ADefaultPawn, public ITalker // Tlaker 인터페이스를 상속한 플레이어 폰 클래스
{
	GENERATED_BODY()

public:
	ATalkingPawn();
	
	UPROPERTY()
	class UBoxComponent* TalkingCollider; // 폰 충돌 영역 박스

	UFUNCTION() // 충돌시 호출할 함수
	void OnTalkOverlap(UPrimitiveComponent* HitComp, AActor * OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
