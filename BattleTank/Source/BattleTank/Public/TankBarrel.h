// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent),hidecategories=("Collision"))

class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max down movement +1 is max up movement
	void Elevate(float  RelativeSpeed);
private:
	UPROPERTY(EditAnywhere,Category=Setup)
	float MaxDegreePerSec = 5;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegree = 0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MAxElevationDegree = 40;
};
