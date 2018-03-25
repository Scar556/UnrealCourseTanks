// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTurret;
class AProjectile;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;


public:
	// Sets default values for this pawn's properties
	void AimAt(FVector HitLocation);

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000.f; // TODO: Find sensible default value
	UPROPERTY(EditAnywhere, Category = SetUp)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	// Creates a local reference for spawning projectiles
	UTankBarrel* Barrel;

	float ReloadTimeInSeconds = 3.f;
	double LastFireTime = 0;
};
