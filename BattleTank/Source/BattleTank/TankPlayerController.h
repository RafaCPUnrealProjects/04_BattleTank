// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleTank.h"
#include "Camera/PlayerCameraManager.h"
#include "Engine/World.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//forward declarations
class UTankAimingComponent;

/**
 * Responsible for helping the player aim
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const;

	bool GetLookDirection(FVector2D &ScreenLocation, FVector &WorldDirection) const;

	UFUNCTION()
	void OnPossessedTankDeath();

	virtual void SetPawn(APawn * InPawn) override;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;
	
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;
	
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;
};
