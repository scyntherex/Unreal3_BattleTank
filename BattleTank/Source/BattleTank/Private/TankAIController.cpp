// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
//#include "BattleTank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AITank = GetAITank();
	auto PlayerTank = GetPlayerTank();
	if (!AITank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possessing a tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI: %s found Player: %s"),
			*AITank->GetName(), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float deltaTime) {
	//Super
	Super::Tick(deltaTime);
	// Aim towards crosshair
	if (GetPlayerTank()) {
		//TODO Move towards player
		//Aim towards player
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		//TODO Fire at player
	}
}

ATank* ATankAIController::GetAITank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}