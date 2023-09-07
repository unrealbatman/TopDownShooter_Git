// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Pickup.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIABLO__API UPickup : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPickup();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere, category = "Pickup Properties")
		FRotator RotationRate =  FRotator(0,180,0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Pickup Properties")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Pickup Properties")
		 UStaticMesh* StaticMesh;
	
	UPROPERTY(EditAnywhere, category = "Pickup Properties")
		UThumbnailInfo* thumbnail;

	UPROPERTY(BlueprintReadOnly)
	UStaticMeshComponent* Pickup_Mesh;
		
};
