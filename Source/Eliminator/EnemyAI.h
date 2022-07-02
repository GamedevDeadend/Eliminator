// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAI.generated.h"

/**
 * 
 */
UCLASS()
class ELIMINATOR_API AEnemyAI : public AAIController
{
	GENERATED_BODY()

	private:

		virtual void Tick(float DeltaTime) override;
		APawn *PlayerPawn;



	protected:

		virtual void BeginPlay() override;

	
	public:

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		class UBehaviorTree *AIBehavior;
};
