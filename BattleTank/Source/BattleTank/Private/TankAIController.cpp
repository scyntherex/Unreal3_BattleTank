// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "BattleTank.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe our local method to the tank's death
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Broadcast received."));
	GetPawn()->DetachFromControllerPendingDestroy();
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


