// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Killable.h"
#include "Undead.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUndead : public UKillable // Killable(UInterface)를 상속받음 
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPSHOOTER_API IUndead: public IKillable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool IsDead() override; // Killable의 함수를 오버라이딩
	virtual void Die() override;
	virtual void Turn();
	virtual void Banish();
};
