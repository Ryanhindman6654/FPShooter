// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Blueprint/UserWidget.h"

void AMyGameModeBase::ButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Button Clicked!"));
	
}


void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (UIWidgetClass) {
		UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(), UIWidgetClass);
		if (Menu) {
			Menu->AddToViewport();
			GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
		}
	}
}


