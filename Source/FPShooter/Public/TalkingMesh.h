// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Talker.h"
#include "TalkingMesh.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API ATalkingMesh : public AStaticMeshActor, public ITalker // 인터페이스 함수를 호출할 메시 액터
{
	GENERATED_BODY()
	
public:
	ATalkingMesh();
	void StartTalking_Implementation(); // 인터페이스 함수 재정의
};
