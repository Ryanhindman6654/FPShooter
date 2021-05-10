// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Killable.generated.h"

// This class does not need to be modified.
UINTERFACE(meta = (CannotImplementInterfaceInBlueprint)) // UInterface는 기본적으로 블루프린트에서도 구현할 것을 요구하는데 이를 방지하기 위해 블루프린트로 구현되지않게 마킹했다.
class UKillable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPSHOOTER_API IKillable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, Category = Killable) // 블루프린트에서도 호출할 수 있게 지정자를 추가했다.
	virtual bool IsDead();

	UFUNCTION(BlueprintCallable, Category = Killable)
	virtual void Die();
};
