// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces to the tank body
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);
	

	// This is max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000.f; // Assume 40 tonne tank and 1g acceleration
};
