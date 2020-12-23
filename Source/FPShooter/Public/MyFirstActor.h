// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstActor.generated.h"

UCLASS()
class FPSHOOTER_API AMyFirstActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	AMyFirstActor();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* ChildSceneCoimponent;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BoxOne;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BoxTwo;

};
