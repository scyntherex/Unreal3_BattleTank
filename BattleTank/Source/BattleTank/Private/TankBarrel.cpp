// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond) {
	//move barrel the correct amount this frame

	//given max elevation speed and frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevate called at speed : %f"), DegreesPerSecond);
}


