// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AITank = GetAITank();
	if (!AITank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possessing a tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI: %s"),
			*AITank->GetName());
	}
}

ATank* ATankAIController::GetAITank() const {
	return Cast<ATank>(GetPawn());
}