// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"

// Sets default values for this component's properties
UPickup::UPickup()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;



	// ...
}


// Called when the game starts
void UPickup::BeginPlay()
{
	Super::BeginPlay();

	if (Name.IsEmpty()) {

	}
	else {
		//Pickup_Mesh->SetStaticMesh(StaticMesh);
		GLog->Log("Insinde");
	}

}


// Called every frame
void UPickup::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* owner = GetOwner();
	owner->AddActorLocalRotation(RotationRate*DeltaTime,true);

}

