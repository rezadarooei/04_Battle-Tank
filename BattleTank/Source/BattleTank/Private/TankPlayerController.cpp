// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTannk() const {

	return Cast<ATank>(GetPawn());
}



