// Fill out your copyright notice in the Description page of Project Settings.


#include "NonSelectableCube.h"

bool ANonSelectableCube::IsSelectables()
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Not Selectable");
    return false; // false를 반환하도록 오버라이딩했다.
}

bool ANonSelectableCube::TrySelect()
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Refusing Selection");
    return false; // flase를 반환 
}

void ANonSelectableCube::Deselect()
{
    unimplemented();
}
