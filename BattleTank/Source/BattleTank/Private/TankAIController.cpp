// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float deltaTime) {
	//Super
	Super::Tick(deltaTime);

	auto AITank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	// Aim towards crosshair
	if (PlayerTank) {
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius in cm.

		//Aim towards player
		AITank->AimAt(PlayerTank->GetActorLocation());

		AITank->Fire(); //TODO Don't fire every frame.
	}
}