// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenRedDoor.generated.h"

class ATriggerVolume;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LETMEOUT_API UOpenRedDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenRedDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	UPROPERTY(VisibleAnywhere)
	float m_openAngle{ -66.f };

	UPROPERTY(EditAnywhere)
	ATriggerVolume* m_pressurePlate;

	UPROPERTY(EditAnywhere)
	float m_doorCloseDelay{ 1.f };
	float m_lastDoorOpenTime{};

	AActor* m_actorThatOpens;
	AActor* m_doorOwner;
};
