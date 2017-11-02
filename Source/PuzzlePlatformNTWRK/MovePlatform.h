// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovePlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMNTWRK_API AMovePlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovePlatform();

	UPROPERTY(EditAnywhere)
	float Speed = 15;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
	int32 ActiveTriggers = 1;
};
