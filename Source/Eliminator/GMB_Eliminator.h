// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GMB_Eliminator.generated.h"

/**
 * 
 */
UCLASS()
class ELIMINATOR_API AGMB_Eliminator : public AGameModeBase
{
	GENERATED_BODY()
	public:

		void PawnKilled(APawn *KilledPawn);
		void EndGame(bool bIsPlayerWinner);
};
