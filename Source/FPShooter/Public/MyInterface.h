#pragma once
#include "MyInterface.generated.h"

UINTERFACE()
class FPSHOOTER_API UMyInterface : public UInterface // 먼저 언리얼 인터페이스를 선언하기 위해 UINTERFACE 매크로를 사용한 UMyInterface 클래스를 선언해준다.
{ // UClass 형식이라 UHT에서 관리될 수 있다.
	GENERATED_BODY()
};

class FPSHOOTER_API IMyInterface // 선언된 UMyInterface를 기반으로 생성한 사용자 정의 인터페이스다. (I접두어이기에 UClass가 아니다)
{
	/*
	인터페이스 구현부는 UClass 형식이 아닌데 이러한 이유는 액터가 2개 이상의 부모를 상속받을 경우 2개의 UClass가 만들어지는데 
	이는 최소한의 계층 구조로 이루어져야만 하는 UObject의 기본 컨셉을 망가뜨린다.
	그래서 인터페이스의 구현부는 UClass에서 분리되어야 하며 (UClass를 한개로 유지하기 위해) 네이티브 방식으로 구현한다.
	*/
	GENERATED_BODY()

public:
	virtual FString GetTestName(); // 인터페이스가 가상 함수를 선언하였다. (파생클래스에서 재정의 필요)
};