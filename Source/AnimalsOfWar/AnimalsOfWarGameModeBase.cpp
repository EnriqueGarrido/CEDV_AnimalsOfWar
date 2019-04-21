// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimalsOfWarGameModeBase.h"
#include "AnimalsOfWarPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "AnimalsOfWarHUD.h"
#include "Engine.h"


AAnimalsOfWarGameModeBase::AAnimalsOfWarGameModeBase() 
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	DefaultPawnClass = nullptr;
	PlayerControllerClass = AAnimalsOfWarPlayerController::StaticClass();
	HUDClass = AAnimalsOfWarHUD::StaticClass();
}

void AAnimalsOfWarGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::CreatePlayer(GetWorld(), 0, true);
	UGameplayStatics::CreatePlayer(GetWorld(), 1, true);

	// Init the remaining time
	RemainingTurnTime = MaxTurnTime;
	HUDTime = floor(RemainingTurnTime);
}

void AAnimalsOfWarGameModeBase::Tick(float DeltaTime)
{
	RemainingTurnTime -= DeltaTime;

	// A second 
	if (HUDTime > floor(RemainingTurnTime)) 
	{
		HUDTime = floor(RemainingTurnTime);
		AAnimalsOfWarHUD* HUD = Cast<AAnimalsOfWarHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		HUD->UpdateCounter(HUDTime);
	}

	// Check turn timeout
	if (RemainingTurnTime <= 0.0f) 
	{
		RemainingTurnTime = MaxTurnTime;
		HUDTime = floor(RemainingTurnTime);

	}

}