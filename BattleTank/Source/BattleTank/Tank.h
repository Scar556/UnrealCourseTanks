// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTurret;
class AProjectile;
class UTankAimingComponent;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:
	// Sets default values for this pawn's properties
	void AimAt(FVector HitLocation);

public:
	ATank();


	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000.f; // TODO: Find sensible default value
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3.f;

	UTankBarrel* Barrel = nullptr; // TODO remove

	double LastFireTime = 0;
};
