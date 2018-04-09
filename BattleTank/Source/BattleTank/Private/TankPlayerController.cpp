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
	//Get world Location through lineTrace 
}