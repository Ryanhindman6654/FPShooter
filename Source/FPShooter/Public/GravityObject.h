// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GravityObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGravityObject : public UInterface // 그래비티 인터페이스
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPSHOOTER_API IGravityObject // GravityObject 인터페이스 구현부
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void EnableGravity(); // 상속한 클래스가 클래스의 특성에 따른 추가요소로 인해 함수를 재정의할 수도 있기에 가상 함수로 선언해준다.
	virtual void DisableGravity();
};
