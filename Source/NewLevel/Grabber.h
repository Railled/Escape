// Copyright V. Makhynko

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWLEVEL_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// How far ahead of the player we car reach
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHande = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what is reached
	void Grab();

	//Called when grab is released
	void Release();

	//Find attached phisics
	void FindPhysicsHandeComponent();

	//setup (assumed) attached input component
	void SetupInputComponent();

	// Return hit for first physics bode in reach
	FHitResult GetFirstPhysicsBodyInReach();

	//Returns current end of reach line
	FVector GetReachLineStart();
	
	//Returns current start of reach line
	FVector GetReachLineEnd();
};
