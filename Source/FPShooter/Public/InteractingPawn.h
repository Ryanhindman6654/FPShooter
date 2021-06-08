// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "InteractingPawn.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API AInteractingPawn : public ADefaultPawn // 플레이어 폰
{
	GENERATED_BODY()
	
public:
	void TryInteract(); // 벨과 상호작용

private:
	virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override; // 키보드 단축키 설정
};
