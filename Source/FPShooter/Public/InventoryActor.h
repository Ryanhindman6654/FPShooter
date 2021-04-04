// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API AInventoryActor : public AStaticMeshActor // 인벤토리로 저장할 수 있는 액터
{
	GENERATED_BODY()
public:
	AInventoryActor(); 
	virtual void PickUp(); // 아이템 획득
	virtual void PutDown(FTransform TargetLocation); // 아이템 버리기(놓기)
};
