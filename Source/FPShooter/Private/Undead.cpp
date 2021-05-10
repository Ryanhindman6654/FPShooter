// Fill out your copyright notice in the Description page of Project Settings.


#include "Undead.h"
// Add default functionality here for any IUndead functions that are not pure virtual.

bool IUndead::IsDead()
{
	return true;
}

void IUndead::Die()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("You can't kill what is already dead. Mwahaha"));
}

void IUndead::Turn()
{
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("I'm feeling!"));
}

void IUndead::Banish()
{
	AActor* Me = Cast<AActor>(this);
	if (Me)
	{
		Me->Destroy();
	}
}	
