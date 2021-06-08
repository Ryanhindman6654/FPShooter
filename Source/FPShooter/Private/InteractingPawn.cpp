// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractingPawn.h"
#include "Interactable.h"
void AInteractingPawn::TryInteract()
{
	APlayerController* MyController = Cast<APlayerController>(Controller); // 폰의 컨트롤러를 플레이어 컨트롤러로 캐스팅
	if (MyController)
	{
		APlayerCameraManager* MyCameraManager = MyController->PlayerCameraManager;
		auto StartLocation = MyCameraManager->GetCameraLocation();
		auto EndLocation = MyCameraManager->GetCameraLocation() + (MyCameraManager->GetActorForwardVector() * 100); // 카메라가 벨을 바라보고 있는 경우
		FHitResult HitResult; // 벨 포인터
		GetWorld()->SweepSingleByObjectType(HitResult, StartLocation, EndLocation, FQuat::Identity, FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects), FCollisionShape::MakeSphere(25), FCollisionQueryParams(FName("Interaction"), true, this)); // 구형 충돌 검출 영역 설정
		if (HitResult.Actor != nullptr)
		{
			if (HitResult.Actor->GetClass()->ImplementsInterface(UInteractable::StaticClass())) // HitResult 액터(벨)에 Interactable 인터페이스가 상속됐을 경우
			{
				if (IInteractable::Execute_CanInteract(HitResult.Actor.Get())) // Interactable::Caninteract을 실행하여 벨 상태가 flase 일 경우
				{
					IInteractable::Execute_PerformInteract(HitResult.Actor.Get()); // Interactable::PerformInteract을 실행하여 벨이 담당하는 문에 상호작용(열기)
				}
			}
		}
	}
}

void AInteractingPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
	InInputComponent->BindAction("Interact", IE_Released, this, &AInteractingPawn::TryInteract); // 액션키(F) 바인딩 (TryInteract 함수 실행)
}
