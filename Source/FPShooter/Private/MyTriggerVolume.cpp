// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVolume.h"
#include "FPShooterGameMode.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject <UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200, 200, 100)); // 박스 컴포넌트의 (인식)범위 설정
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

void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor) // 노티파이가 오버랩된 경우
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s entered me"), *(OtherActor->GetName()))); // 전역 엔진 함수로 UI에 메시지 출력

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);
		MyGameMode->MyStandardDelegate.ExecuteIfBound(); // 바인딩된 함수를 실행
	}
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s left me"), *(OtherActor->GetName())));

	if (GetWorld() != nullptr)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
		AFPShooterGameMode* MyGameMode = Cast<AFPShooterGameMode>(GameMode);
		MyGameMode->MyStandardDelegate.ExecuteIfBound(); // 바인딩된 함수를 실행
	}
}

