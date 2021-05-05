// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityObject.h"

// Add default functionality here for any IGravityObject functions that are not pure virtual.

void IGravityObject::DisableGravity()
{
	AActor* ThisAsActor = Cast<AActor>(this); // 이 인터페이스를 상속받은 액터의 
	if (ThisAsActor != nullptr)
	{
		TArray<UPrimitiveComponent*> PrimitiveComponents;
		ThisAsActor->GetComponents(PrimitiveComponents);
		for (UPrimitiveComponent* Component : PrimitiveComponents)
		{
			Component->SetEnableGravity(false); // 중력을 비활성화한다.
		}
	}

}


void IGravityObject::EnableGravity()
{
	AActor* ThisAsActor = Cast<AActor>(this); // 이 인터페이스를 상속받은 액터의
	if (ThisAsActor != nullptr)
	{
		TArray<UPrimitiveComponent*> PrimitiveComponents;
		ThisAsActor->GetComponents(PrimitiveComponents);
		for (UPrimitiveComponent* Component : PrimitiveComponents)
		{
			Component->SetEnableGravity(true); // 중력을 활성화한다.
		}
	}
}
