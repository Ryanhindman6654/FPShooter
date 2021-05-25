// Fill out your copyright notice in the Description page of Project Settings.


#include "Selectable.h"

// Add default functionality here for any ISelectable functions that are not pure virtual.

bool ISelectable::IsSelectables()
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Selectable");
    return true; // 일반적으론 true를 반환
}

bool ISelectable::TrySelect()
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Accepting Selection");
    return true;
}

void ISelectable::Deselect()
{
    unimplemented();
}
