// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

void UTankTracks::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: Throttle: %f"), *Name, Throttle)

		//TODO: Clamp actual throttle values so player can't make it go faster
}


