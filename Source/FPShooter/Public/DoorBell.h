// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interactable.h"
#include "DoorBell.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API ADoorBell : public AStaticMeshActor, public IInteractable // 벨 액터
{
	GENERATED_BODY()
	
public:
	ADoorBell();
	virtual bool CanInteract_Implementation() override; // 문과 상호작용 가능한지 체크 함수
	virtual void PerformInteract_Implementation() override; // 문과 상호작용 실행 함수

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* DoorToOpen; // 연결할 문의 포인터
	
private:
	bool HasBeenPushed; // 벨 상태
};
