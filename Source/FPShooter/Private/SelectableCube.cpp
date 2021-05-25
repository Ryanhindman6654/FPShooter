// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectableCube.h"
ASelectableCube::ASelectableCube()
{
	MyMesh->SetNotifyRigidBodyCollision(true); // 바디 콜리전 활성화
}

void ASelectableCube::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{	// 물체가 부딪혔을 때 
	if (IsSelectables()) // IsSelectable()을 호출하는데 현재 오버라이딩 상태에 따라 true/false 값을 반환한다.
	{				     // SelectableCube는 IsSelectable()를 따로 오버라이딩하지 않았기 때문에 부모 값인 true를 반환한다. 하지만 이 클래스를 상속받은 NonSelectableCube는 따로 오버라이딩하여 false를 반환한다.
		TrySelect(); // 화면에 메시지 출력
	}
}
