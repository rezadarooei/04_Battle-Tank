// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Engine/World.h"
void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	
		auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI COntrol ncant find Player Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank is %s"), *PlayerTank->GetName())

	}
	
	}
ATank* ATankAIController::GetContolledTank() const {
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank=GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	else {
		return Cast<ATank>(PlayerTank);
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime);
	if (!GetContolledTank()) {
		return;
	}
	if (GetContolledTank()) {
		//TODO move towards player
		//Aim towards player(هدف گیری تانک اصلی)
		GetContolledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//FIre if ready
	}
}
