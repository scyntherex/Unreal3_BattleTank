// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "BattleTank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float deltaTime) {
	//Super
	Super::Tick(deltaTime);

	auto AITank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	// Aim towards crosshair
	if (!ensure(PlayerTank && AITank)) { return; }

	//Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius in cm.

	auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
	//if (!ensure(AimingComponent)) { return; }

	//Aim towards player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if(AimingComponent->GetFiringState() == EFiringStatus::Locked) 
		AimingComponent->Fire(); //TODO Don't fire every frame.
	
}