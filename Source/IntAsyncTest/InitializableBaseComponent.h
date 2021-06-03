// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Initializable.h"
#include "Components/ActorComponent.h"
#include "InitializableBaseComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTASYNCTEST_API UInitializableBaseComponent : public UActorComponent, public IInitializable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInitializableBaseComponent();
	virtual void Initialize_Implementation() override;
	virtual EInitializableState GetStatus_Implementation() override;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	EInitializableState Status;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
