#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "CollisionDebugDrawingPublic.h"
#include "Components/CapsuleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	FVector Start = GetComponentLocation() + DebugOffset;
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	FHitResult Hits;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	

	isOverlap =GetWorld()->OverlapAnyTestByChannel(Start,FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel1,Sphere);
	if (isOverlap == true) {
		DrawDebugLine(GetWorld(), Start, End, FColor::Green);
		
	}
	else {
		DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	}
	
}

