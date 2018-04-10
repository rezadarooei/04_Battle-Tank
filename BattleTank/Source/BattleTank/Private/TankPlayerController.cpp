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
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	 auto ScreenLocation=FVector2D(CrosssHairXLocation*ViewPortSizeX,CrosssHairYLocation*ViewPortSizeY);
	UE_LOG(LogTemp,Warning,TEXT("location is: %s"),*ScreenLocation.ToString())
	//find crosshair Position
	//"De-project" Screen position of the Crosshair to a world direction
	//Line-Trace Long that  look direction,and see what we hit(up to max range)
	Hitlocation = FVector(1.0f);
	return true;
}