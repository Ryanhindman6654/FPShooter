// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PostBeginPlay.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint)) // 블루프린트로 노출하려면 UINTERFACE의 지정자(meta)를 설정해줘야 함
class UPostBeginPlay : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPSHOOTER_API IPostBeginPlay
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, Category = Test) // 블루프린트로 노출될 수 있도록 지정자(Callable, Category) 설정
	virtual void OnPostBeginPlay();
};
