// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

/*UTankTrack::UTankTrack() {
	PrimaryComponentTick.bCanEverTick = true;
}*/

void  UTankTrack::OnRegister() {
	Super::OnRegister();
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay() {
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit) {
	UE_LOG(LogTemp, Warning, TEXT("I'm hit."));
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	//Work out required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//Calcuale and apply sideways for (F = m * a)
	auto TankRootComp = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRootComp->GetMass() * CorrectionAcceleration) / 2;

	TankRootComp->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle) {
	
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


