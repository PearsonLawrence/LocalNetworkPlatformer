// Fill out your copyright notice in the Description page of Project Settings.

#include "MovePlatform.h"


AMovePlatform::AMovePlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}

void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector location = GetActorLocation();
		float JournyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JournyTravelled = (location - GlobalStartLocation).Size();

		if (JournyTravelled >= JournyLength)
		{
			FVector SwapLocation = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = SwapLocation;
		}
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		
		location += Speed * DeltaTime * Direction;
		SetActorLocation(location);
	}
	
}
