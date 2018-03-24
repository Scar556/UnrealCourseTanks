// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI controller can't find player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller found player: %s"), *(PlayerTank->GetName()));
	};
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// move towards the player

		// aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire if ready
	}
}

	ATank* ATankAIController::GetControlledTank() const
	{
		return Cast<ATank>(GetPawn());
	}

	ATank* ATankAIController::GetPlayerTank() const
	{
		auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (!PlayerPawn) { return nullptr; }

		return Cast<ATank>(PlayerPawn);
	}