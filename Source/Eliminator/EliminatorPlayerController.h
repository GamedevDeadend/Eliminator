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

	private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Settings", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UUserWidget> PlayerHudClass;


	protected:

	virtual void BeginPlay() override;

	
	public:

	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;


};
