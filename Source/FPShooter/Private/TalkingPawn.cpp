// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingPawn.h"
#include "Components/BoxComponent.h"


ATalkingPawn::ATalkingPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	TalkingCollider = CreateDefaultSubobject<UBoxComponent>("TalkCollider");
	TalkingCollider->SetBoxExtent(FVector(200, 200, 100)); // 충돌 영역 설정
	TalkingCollider->OnComponentBeginOverlap.AddDynamic(this, &ATalkingPawn::OnTalkOverlap); // 충돌 시 OnTalkerOverlap 함수 호출
	TalkingCollider->AttachTo(RootComponent);
}

void ATalkingPawn::OnTalkOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->ImplementsInterface(UTalker::StaticClass())) // 폰 액터가 아닌 충돌한 액터(OtherActor)의 인터페이스 함수 (StartTalking) 함수 실행
	{
		ITalker::Execute_StartTalking(OtherActor); // StartTalking을 호출하기 위해 인터페이스의 상속이 필요했으며, Excute_를 붙여 OtherActor의 StartTalking 함수를 호출하도록 했다.
	}
}
