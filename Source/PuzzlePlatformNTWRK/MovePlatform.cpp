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
}

void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector location = GetActorLocation();
		location += FVector(Speed * DeltaTime, 0, 0);
		SetActorLocation(location);
	}
	
}
