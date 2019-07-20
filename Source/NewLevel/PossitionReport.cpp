 // Fill out your copyright notice in the Description page of Project Settings.


#include "PossitionReport.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPossitionReport::UPossitionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts GetOwner()->GetTransform().GetLocation().ToString();
void UPossitionReport::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Object %s at %s!"), *ObjectName, *ObjectPos);
	
}


// Called every frame
void UPossitionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

