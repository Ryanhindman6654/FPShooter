// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/Classes/Particles/ParticleSystemComponent.h"
#include "BarracksUnit.generated.h"


UCLASS()
class FPSHOOTER_API ABarracksUnit : public ACharacter // 배럭에서 스폰되는 유닛
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABarracksUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	UParticleSystemComponent* VisualRepresentation; // 스폰될 파티클

};
