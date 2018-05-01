// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel :: Elevate(float RelativeSpeed) {

	//Move The 	Barrel the RightAmount of this Frame
	//Give Max Elevation Speed
	RelativeSpeed=FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed*MaxDegreePerSec*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegree, MAxElevationDegree);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	
	
}