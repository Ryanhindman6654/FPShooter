// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "HierachyActor.generated.h"

UCLASS()
class FPSHOOTER_API AHierachyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHierachyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class USceneComponent* Root; 

	UPROPERTY()
	USceneComponent* ChildScenceComponent;

	UPROPERTY()
	class UStaticMeshComponent* BoxOne;

	UPROPERTY()
	UStaticMeshComponent* BoxTwo;
};
