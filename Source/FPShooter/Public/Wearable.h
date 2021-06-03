// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Wearable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWearable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPSHOOTER_API IWearable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Wearable) 
	int32 GetStrengthRequirement(); 

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Wearable) // virtual가 아닌 인터페이스 함수를 C++에서 구현하기 위해서는 자식 클래스에서 오버라이드할 때 함수에다 _Implementation를 추가해준다.
	bool CanEquip(APawn* Wearer); 

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Wearable)
	void OnEquip(APawn* Wearer);
};
