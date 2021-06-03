// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wearable.h"
#include "Boots.generated.h"

UCLASS()
class FPSHOOTER_API ABoots : public AActor, public IWearable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoots();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnEquip_Implementation(APawn* Wearer) override // _Implementation를 추가하면 인터페이스의 원본 함수가 가상 함수가 아니더라도 기존처럼 오버라이드가 가능하다.
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Item being worn"); 
	}

};
