// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AnimalsOfWarHUD.generated.h"

/**
 * 
 */
UCLASS()
class ANIMALSOFWAR_API AAnimalsOfWarHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AAnimalsOfWarHUD();

	// Reference to HUD widget
	UPROPERTY()
		TWeakObjectPtr<class UUserWidget> pHUDWidget;

	// Variable to hold specifically the grenades TextBlock in the widget
	UPROPERTY()
		TWeakObjectPtr<class UTextBlock> pNumGrenadesText;

	// Variable to hold specifically the sheeps TextBlock in the widget
	UPROPERTY()
		TWeakObjectPtr<class UTextBlock> pNumSheepsText;

	// Reference to HUD Widget class
	class UClass* pHUDWidgetClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Increases Sheeps text widget
	UFUNCTION()
		void SetNumSheeps(int NumGrenades);

	// Increases Grenades text widget
	UFUNCTION()
		void SetNumGrenades(int NumSheeps);
};
