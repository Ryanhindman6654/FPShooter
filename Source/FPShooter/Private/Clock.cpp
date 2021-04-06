// Fill out your copyright notice in the Description page of Project Settings.

#include "Clock.h"
#include "TimeOfDayHandler.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AClock::AClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScenceComponent = CreateDefaultSubobject<USceneComponent>("RootSceneComponent");
	ClockFace = CreateDefaultSubobject<UStaticMeshComponent>("ClockFace");
	HourHand = CreateDefaultSubobject<UStaticMeshComponent>("HourHand");
	MinuteHand = CreateDefaultSubobject<UStaticMeshComponent>("MinuteHand");
	HourHandle = CreateDefaultSubobject<USceneComponent>("HourHandle");
	MinuteHandle = CreateDefaultSubobject<USceneComponent>("MinuteHandle");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));

	if (MeshAsset.Object != nullptr)
	{
		ClockFace->SetStaticMesh(MeshAsset.Object);
		HourHand->SetStaticMesh(MeshAsset.Object);
		MinuteHand->SetStaticMesh(MeshAsset.Object);
	}

	// 컴포넌트 상속관계 설정
	RootComponent = RootScenceComponent;
	ClockFace->AttachTo(RootScenceComponent);
	HourHandle->AttachTo(RootScenceComponent);
	MinuteHandle->AttachTo(RootScenceComponent);
	HourHand->AttachTo(HourHandle);
	MinuteHand->AttachTo(MinuteHandle);

	// 초침 및 시계 스케일 설정
	ClockFace->SetRelativeTransform(FTransform(FRotator(90, 0, 0), FVector(10, 0, 0), FVector(2, 2, 0.1)));
	HourHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 25), FVector(0.1, 0.1, 0.5)));
	MinuteHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 50), FVector(0.1, 0.1, 1)));
}

// Called when the game starts or when spawned
void AClock::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> TimeOfDayHandlers; // 액터 주소를 담기 위한 포인터 배열
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeOfDayHandler::StaticClass(), TimeOfDayHandlers); 
	// ATimeOfDayHandler 액터가 월드에 존재할 경우, 그 액터의 주소를 TimeOfDayHandlers 포인터에 넣는다.

	if (TimeOfDayHandlers.Num() != 0)
	{
		auto TimeOfDayHandler = Cast<ATimeOfDayHandler>(TimeOfDayHandlers[0]); // TimeOfDayHandlers[0]번 인덱스의 액터를 ATimeOfDayHandler 클래스로 다운캐스팅
		MyDelegateHandle = TimeOfDayHandler->OnTimeChanged.AddUObject(this, &AClock::TimeChaned); 
		// 해당 클래스(ATimeOfDayHandler)에 선언된 델리게이트(OnTimeChanged)에 TimeChaned() 함수를 바인딩한다. 바인딩한 결과값을 핸들에 반환한다.
	}
}

// Called every frame

void AClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AClock::TimeChaned(int32 Hours, int32 Minutes) // 바인딩할 함수
{
	HourHandle->SetRelativeRotation(FRotator(0, 0, 30 * Hours)); // 시침의 각도 30도씩 변화시킨다.
	MinuteHandle->SetRelativeRotation(FRotator(0, 0, 6 * Minutes)); // 분침의 각도를 1도씩 변화시킨다.
}

