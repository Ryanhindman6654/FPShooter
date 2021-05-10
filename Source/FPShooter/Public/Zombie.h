// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Undead.h"
#include "Zombie.generated.h"

UCLASS()
class FPSHOOTER_API AZombie : public AActor, public IUndead // 좀비는 Killable를 상속받은 Undead를 상속받아 오버라이딩 된 Die()가 호출되기에 삭제되지 않는다.
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZombie();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
