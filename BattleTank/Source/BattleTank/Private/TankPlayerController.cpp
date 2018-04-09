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
ATank* ATankPlayerController::GetControlledTannk() const {

	return Cast<ATank>(GetPawn());

}
