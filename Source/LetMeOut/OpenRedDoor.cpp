// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenRedDoor.h"
#include "Engine/TriggerVolume.h"

// Sets default values for this component's properties
UOpenRedDoor::UOpenRedDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenRedDoor::BeginPlay()
{
	Super::BeginPlay();
	
	m_actorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void UOpenRedDoor::OpenDoor()
{
	UE_LOG(LogTemp, Display, TEXT("The Red Door is open\n"));

	FRotator rotator(0.f, 0.f, 90.f);
	GetOwner()->SetActorRotation(rotator);
}


// Called every frame
void UOpenRedDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if (m_pressurePlate->IsOverlappingActor(m_actorThatOpens))
	{
		OpenDoor();
	}
}

