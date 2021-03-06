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
	// -1 is max downward movement and +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Set Up")
	float MaxDegreesPerSecond = 20.f;

	UPROPERTY(EditDefaultsOnly, Category = "Set Up")
	float MaxElevationDegrees = 30.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Set Up")
	float MinElevationDegrees = 0.f;
	
};
