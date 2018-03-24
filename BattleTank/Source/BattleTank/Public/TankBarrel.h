// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = "Set Up")
	float MaxDegreesPerSecond = 20.f;
	UPROPERTY(EditAnywhere, Category = "Set Up")
	float MaxElevationDegrees = 30.f;
	UPROPERTY(EditAnywhere, Category = "Set Up")
	float MinElevationDegrees = 0.f;
	
};
