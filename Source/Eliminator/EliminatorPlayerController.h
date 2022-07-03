// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EliminatorPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ELIMINATOR_API AEliminatorPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:

		virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
};
