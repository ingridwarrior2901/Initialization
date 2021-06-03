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
	SD::WhenAll<int32>({
		SD::MakeReadyFuture<int32>(1),
		SD::MakeReadyFuture<int32>(2),
		SD::MakeReadyFuture<int32>(4) })
                    .Then([this](const TArray<int32>& Result)
                        {
                            int32 Total = 0;
                            for (const int32 Value : Result)
                            {
                                Total += Value;
                            }
                            return Total;
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

