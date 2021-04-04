// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVolume.h"
#include "FPShooterGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject <UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200, 200, 100)); // 박스 컴포넌트의 (인식)범위 설정
	// 해당 액터에는 델리게이트 두 개를 사용했다. 노티파이가 발생했을 때 두 개의 델리게이트가 호출(Execute)되는 방식
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor) // 노티파이가 오버랩된 경우 (OtherActor : 겹쳐진 상대 액터)
{
	// MyTrigerVolume 액터에서 다른 액터가 겹쳐질 경우 해당 함수가 호출된다. OtherActor는 겹쳐진 상대 액터다.
	Super::NotifyActorBeginOverlap(OtherActor);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s entered me"), *(OtherActor->GetName()))); // 전역 엔진 함수로 UI에 메시지 출력

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);
		MyGameMode->MyParameterDelegate.ExecuteIfBound(FLinearColor(0, 0, 255, 8)); // 바인딩된 함수를 실행(파라미터 추가)
		MyGameMode->MyDynamicMulticastDelegateSignature.Broadcast(); // 바인딩된 함수 모두 실행(브로드캐스팅)
	}
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	// 겹쳐진 액터가 겹쳐지지 않을 때 (겹친 액터가 떠날 때) 호출되는 함수다.
	Super::NotifyActorEndOverlap(OtherActor);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s left me"), *(OtherActor->GetName())));

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);
		MyGameMode->MyParameterDelegate.ExecuteIfBound(FLinearColor(0, 0, 255, 8)); // 바인딩된 함수를 실행(파라미터 추가)
		MyGameMode->MyDynamicMulticastDelegateSignature.Broadcast();
	}
}

