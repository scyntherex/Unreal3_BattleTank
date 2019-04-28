// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	
	virtual void Tick(float deltaTime) override;

	virtual void BeginPlay() override;

private:
	//Start the tank moving barrel so that a shot would it where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

	virtual bool GetSightRayHitLocation(FVector&) const;
};
