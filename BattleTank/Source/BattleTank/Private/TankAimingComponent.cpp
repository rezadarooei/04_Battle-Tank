// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include"Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;//TODO should this tick

	// ...
}


void UTankAimingComponent::SetBarrelRefrence(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	//UGameplayStatics* VolicityCounter;
	//calculate out lunch velocity
	//TArray<AActor*> ActorsToIgnore;
	bool bIsSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLunchVelocity,
		StartLocation,
		HitLocation,
		LunchSpeed,
// 		false,
// 		0.f,
// 		0.f,
 		ESuggestProjVelocityTraceOption::DoNotTrace
// 		FCollisionResponseParams::DefaultResponseParam,
// 		ActorsToIgnore,
// 		true
	);
	if (bIsSolution) {
		auto AimDirection = OutLunchVelocity.GetSafeNormal();
		//FRotator AimRotation=OutLunchVelocity.Rotation
		MoveBarrelTowords(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f  Aim Found"), Time)
	}
	else {
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f No Aim Found"), Time)
	}

	
}

void UTankAimingComponent::MoveBarrelTowords(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;
	Barrel->Elevate(5);//TODO remove Magic Number
}

