// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Initializable.generated.h"

UENUM(BlueprintType)
enum class EInitializableState: uint8
{
	Uninitialized,
    Initializing,
    Initialized,
    InitializationFailed
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInitializable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INTASYNCTEST_API IInitializable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Initializable component")
    void Initialize();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Initializable component")
    EInitializableState GetStatus();
};
