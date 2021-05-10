// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Killable.h"
#include "Snail.generated.h"

UCLASS()
class FPSHOOTER_API ASnail : public AActor, public IKillable // 달팽이는 Killable을 상속 받아 Die를 호출할 때 액터가 삭제된다.
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnail();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
