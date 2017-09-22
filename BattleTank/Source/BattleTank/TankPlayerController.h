// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleTank.h"
#include "Tank.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

private:
	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const;

	bool GetLookDirection(FVector2D &ScreenLocation, FVector &WorldDirection) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;
	
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;
};
