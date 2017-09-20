// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto Tank = GetPlayerTank();
	if (!Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank = %s"), *(Tank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(PlayerPawn) 
	{
		return Cast<ATank>(PlayerPawn);
	}
	else
	{
		return nullptr;
	}

}
