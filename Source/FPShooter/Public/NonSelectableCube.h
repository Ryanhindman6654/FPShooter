// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SelectableCube.h"
#include "NonSelectableCube.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API ANonSelectableCube : public ASelectableCube // false를 반환하는 큐브 액터
{
public:
	GENERATED_BODY()
	
	virtual bool IsSelectables() override; // 조부모 인터페이스 함수를 오버라이딩
	virtual bool TrySelect() override;
	virtual void Deselect() override;
};
