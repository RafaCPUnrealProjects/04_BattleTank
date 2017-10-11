// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = this->GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (PlayerTank)
	{
		// move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		AimingComponent->Fire(); //TODO dont fire every frame
	}
}

