// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FPSHOOTER_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	public:

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = UIFuncs)
	void ButtonClicked();

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = UI)
	TSubclassOf<class UUserWidget> UIWidgetClass;
};
