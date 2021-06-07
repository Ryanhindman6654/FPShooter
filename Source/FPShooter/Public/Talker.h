// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Talker.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTalker : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPSHOOTER_API ITalker 
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Talk)
	void StartTalking(); // 인터페이스 함수 선언(블루프린트에서도 정의될 수 있다.)
};
