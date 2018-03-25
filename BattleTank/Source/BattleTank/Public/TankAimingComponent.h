// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Aiming,
	Locked,
	Reloading
};

//Forward Declaration
class UTankBarrel;
class UTurret;

//Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTurret* TurretToSet);
	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	//Will be used by a child
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringStatus = EFiringState::Aiming;

private:
	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);
};
