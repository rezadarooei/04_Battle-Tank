// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;
private:
	ATank* GetControlledTannk() const;
	//Start Tank Moving the barrel so that shot would hit there
	//Crosshair intersect the the world
	void AimTowardCrosshair();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetlookvectorhitLocation(FVector LookDirection, FVector & HitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrosssHairXLocation = .5;
	UPROPERTY(EditAnywhere)
	float CrosssHairYLocation = .33333;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

};
