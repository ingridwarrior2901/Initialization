// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Initializable.h"
#include "GameFramework/Actor.h"
#include "InitializableActor.generated.h"

UCLASS()
class INTASYNCTEST_API AInitializableActor : public AActor, public IInitializable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInitializableActor();
	
	virtual void Initialize_Implementation() override;
	virtual EInitializableState GetStatus_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	EInitializableState Status;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
