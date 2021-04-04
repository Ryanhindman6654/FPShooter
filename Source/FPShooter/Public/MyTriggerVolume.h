// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTriggerVolume.generated.h"

UCLASS()
class FPSHOOTER_API AMyTriggerVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* TriggerZone; // 일반적으로 간단한 충돌을 처리하기 위해 사용되는 상자 컴포넌트

	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override; // 액터의 콜리전이 다른 액터와 오버랩(겹침)됐을 때 알려주는 이벤트(함수)

	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override; // 액터의 콜리전이 오버랩이 끝났을 때 알려주는 이벤트(함수)

};
