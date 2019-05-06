// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Spin(float DegreesPeSecond) {
	auto ClampedSpeed = FMath::Clamp<float>(DegreesPeSecond, -1.0, 1.0);
	auto DirectionChange = ClampedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewDirection = RelativeRotation.Yaw + DirectionChange;
	SetRelativeRotation(FRotator(0, NewDirection, 0));
}


