// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

void UTankTracks::SetThrottle(float Throttle)
{

		//TODO: Clamp actual throttle values so player can't make it go faster

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); //Had to cast down to Primitive as the initial parent class has no physics
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


