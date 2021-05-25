// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicsCube.h"
#include "Selectable.h"
#include "SelectableCube.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API ASelectableCube : public APhysicsCube, public ISelectable // true를 반환하는 큐브 액터
{
public:
	GENERATED_BODY()
	
	ASelectableCube();
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
