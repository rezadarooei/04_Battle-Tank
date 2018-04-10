// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("We are in begin play"))
		auto ControlledTank = GetControlledTannk();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Pawn is not there"))
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Pawn is %s"), *ControlledTank->GetName())
	}
	

}
// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTannk() const {

	return Cast<ATank>(GetPawn());

}
void ATankPlayerController::AimTowardCrosshair() {
	if (!GetControlledTannk()) {return;	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("Location is: %s"), *HitLocation.ToString());
	}
	
	//Get world Location of lineTrace through crosshair
	//if hits landscape
		//tell controlledTank to aim this point
}
bool ATankPlayerController::GetSightRayHitLocation(FVector& Hitlocation) const{
	//find crosshair Position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation=FVector2D(CrosssHairXLocation*ViewPortSizeX,CrosssHairYLocation*ViewPortSizeY);
		//"De-project" Screen position of the Crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("location is: %s"), *LookDirection.ToString())
	}

	//Line-Trace Long that  LookDirection,and see what we hit(up to max range)
	Hitlocation = FVector(1.0f);
	return true;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection) const {

	FVector CameraWorldLocation;//to be discarded not important
	return DeprojectScreenPositionToWorld(ScreenLocation.X
		, ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
	

}