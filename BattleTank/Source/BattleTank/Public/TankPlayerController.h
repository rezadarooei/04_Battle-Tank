// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;
private:
	ATank* GetControlledTannk() const;
	//Start Tank Moving the barrel so that shot would hit there
	//Corshair intersect the the world
	void AimTowardCrosshair();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

	bool GetSightRayHitLocation(FVector& Hitlocation) const;
};
