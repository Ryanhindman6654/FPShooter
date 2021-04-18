// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"
#include "MyGameModeBase.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Controller)
	{
		float len = lastInput.Size();
		if (len > 1.f) // 유닛속도(스케일)가 1.0f을 초과하면(Forward(1) + Right(1))
		{
			lastInput /= len; // 1으로 정규화
		}
		AddMovementInput(GetActorForwardVector(), lastInput.Y); // 수직 이동
		AddMovementInput(GetActorRightVector(), lastInput.X); // 수평 이동
		lastInput.Set(0.f, 0.f); // 틱이 끝나면 XY를 0으로 초기화 시켜주는데 
		// 이는 버튼을 한 번만 누른 후 때어도 그 값(XY)은 계속 적용되어 캐릭터가 계속 이동하는 것을 방지하기 위함이다.
	}

}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AWarrior::Forward); // 캐릭터가 Forward와 관련된 키 입력(w,s)을 받을시 키와 매핑된 스케일을 적용하여 Forward() 함수를 실행한다. 
	PlayerInputComponent->BindAxis("Back", this, &AWarrior::Back);
	PlayerInputComponent->BindAxis("Right", this, &AWarrior::Right);
	PlayerInputComponent->BindAxis("Left", this, &AWarrior::Left);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AWarrior::Jump);
	PlayerInputComponent->BindAction("HotKey_UIButton_Spell", EInputEvent::IE_Pressed, this, &AWarrior::Activity_Spell);
}

void AWarrior::Forward(float amount)
{
	
	/*AddMovementInput(GetActorForwardVector(), amount);
	GetActorForwardVector는 캐릭터를 스케일 값만큼 전진/후진 시키는 함수
	입력한 키의 스케일(amount)이 양수 값(w)이면 전진 음수 값(s)이면 후진한다.*/

	lastInput.Y += amount;
	
}

void AWarrior::Back(float amount)
{
	lastInput.Y -= amount;
}

void AWarrior::Right(float amount)
{
	lastInput.X += amount;
}

void AWarrior::Left(float amount)
{
	lastInput.X -= amount;
}

void AWarrior::Jump()
{
	bPressedJump = true;
}

void AWarrior::Activity_Spell()
{
	auto MyGameMode = Cast<AMyGameModeBase>(GetWorld()->GetAuthGameMode());
	MyGameMode->ButtonClicked();
}





