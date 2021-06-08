// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Openable.h"
#include "Interactable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API ADoor : public AStaticMeshActor, public IInteractable, public IOpenable // 문 액터
{
	GENERATED_BODY()
	
public:
	ADoor();

	UFUNCTION()
	virtual bool CanInteract_Implementation() override { return IInteractable::CanInteract_Implementation(); } // 미구현

	UFUNCTION()
	virtual void PerformInteract_Implementation() override; // 미구현

	UFUNCTION()
	virtual void Open_Implementation() override; // IOpenable::Open 인터페이스 함수 오버라이딩 

};
