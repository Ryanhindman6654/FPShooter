// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

DECLARE_DELEGATE(FPickedupEventSignature) // 델리게이트 시그니처 선언

UCLASS()
class FPSHOOTER_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	FPickedupEventSignature OnPickedUp; // 델리게이트 선언

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override; // 다른 액터와 겹쳐질 경우

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyMesh;

	UPROPERTY()
	class URotatingMovementComponent* RotatingComponent; // 지정한 속도로 회전하는 컴포넌트

};
