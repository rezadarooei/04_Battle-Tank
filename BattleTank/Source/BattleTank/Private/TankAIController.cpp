// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("We are in begin play AI"))
		auto AIControlled = GetContolledTank();
	if (!AIControlled) {
		UE_LOG(LogTemp, Warning, TEXT("Pawn is not there"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn AI is %s"), *AIControlled->GetName())

	}
}
ATank* ATankAIController::GetContolledTank() const {
	return Cast<ATank>(GetPawn());

}

