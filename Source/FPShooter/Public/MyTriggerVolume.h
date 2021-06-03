// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTriggerVolume.generated.h"

DECLARE_EVENT(AMyTriggerVolume, EPlayerEntered) // 이벤트 매크로 함수(이벤트를 사용할 클래스, 이 함수의 시그니처) 
// 해당 이벤트의 Broadcast()를 호출할 수 있는 유일한 클래스다.

UCLASS()
class FPSHOOTER_API AMyTriggerVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTriggerVolume();
	
	EPlayerEntered OnPlayerEntered; // 시그니처를 기반으로 이벤트 선언 (이벤트는 이 클래스에서만 사용할 수 있다)

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
