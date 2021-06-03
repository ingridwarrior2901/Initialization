// Fill out your copyright notice in the Description page of Project Settings.


#include "InitializableActor.h"

#include "../../Plugins/SDFutureExtensions/Source/SDFutureExtensions/Public/ExpectedFuture.h"
#include "../../Plugins/SDFutureExtensions/Source/SDFutureExtensions/Public/FutureExtensionsStaticFuncs.h"

// Sets default values
AInitializableActor::AInitializableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AInitializableActor::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}

void AInitializableActor::Initialize_Implementation()
{
//TODO Implement
	Status = EInitializableState::Initialized;
//TODO EXAMPLE
	TArray<UActorComponent*> InitializableComponents = GetComponentsByInterface(UInitializable::StaticClass());
	TArray<SD::TExpectedFuture<EInitializableState>> InitializableComponentsFutures;

	for (UActorComponent* Element : InitializableComponents)
	{
		SD::TExpectedFuture<EInitializableState> CompFuture = SD::Async([&Element]()
		{
			IInitializable::Execute_Initialize(Element);
			return IInitializable::Execute_GetStatus(Element);
		});
		InitializableComponentsFutures.Add(CompFuture);
	}
	SD::WhenAll<EInitializableState>(InitializableComponentsFutures)
                    .Then([this](const TArray<EInitializableState>& Result)
                        {
                          //TODO: 
                            return EInitializableState::Initialized;
                        });
}

EInitializableState AInitializableActor::GetStatus_Implementation()
{
	return Status;
}



// Called every frame
void AInitializableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

