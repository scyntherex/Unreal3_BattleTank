// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player controller not possessing a tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player: %s"),
			*ControlledTank->GetName());
	}
}

//Tick
void ATankPlayerController::Tick(float deltaTime) {
	//Super
	Super::Tick(deltaTime);
	// Aim towards crosshair
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	//Get world location if linetrace through crosshair
	//If hits landscape
		//Tell controlled tank to aim at this point
}


