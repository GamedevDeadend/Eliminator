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

	AGMB_Eliminator();

	protected:

		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

	public:

		void PawnKilled(APawn *KilledPawn);
		void EndGame(bool bIsPlayerWinner);

	UPROPERTY(EditAnywhere, Category = "Spawn Enemies Attributes")
	TSubclassOf<class APlayerBase> EnemyBPClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true), Category  = "Spawn Enemies Attributes")
	float SpawnTimer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category  = "Spawn Enemies Attributes")
	FVector SpawnLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true), Category  = "Spawn Enemies Attributes")
	float XRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true), Category  = "Spawn Enemies Attributes")
	float YRadius;
};
