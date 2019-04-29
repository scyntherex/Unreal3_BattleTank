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

	FVector HitLocation; // Out param
	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("Hit Loc: %s"), *HitLocation.ToString());
		
		//Tell controlled tank to aim at this point
	}
}

//Get world location if linetrace through crosshair, ret true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find crosshair pos
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation,
		ViewportSizeY * CrossHairYLocation);

	
	//"de-project" screen pos of crosshair to a world projection
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s "), 
			*LookDirection.ToString());
	}
	
	//line trace along that look direction, see wat we hit (up to max range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	
	FVector CameraWorldProjection;
	
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y,
		CameraWorldProjection, 
		LookDirection
	);
}

