// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to applu forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	//This is max force per track, in Ns.
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 35000000.0;//assume tank is 40 tonne, and 1g acc

private:
	//UTankTrack();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void OnRegister() override;

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit);

};
