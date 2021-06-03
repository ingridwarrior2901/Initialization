// Fill out your copyright notice in the Description page of Project Settings.


#include "InitializableBaseComponent.h"

// Sets default values for this component's properties
UInitializableBaseComponent::UInitializableBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInitializableBaseComponent::Initialize_Implementation()
{

	Status = EInitializableState::Initialized;
}

EInitializableState UInitializableBaseComponent::GetStatus_Implementation()
{
	return Status;
}


// Called when the game starts
void UInitializableBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInitializableBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

