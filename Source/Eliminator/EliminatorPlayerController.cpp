// Fill out your copyright notice in the Description page of Project Settings.


#include "EliminatorPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "EnemyAI.h"
#include"EngineUtils.h"


void AEliminatorPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    if( !bIsWinner )
    {
        UE_LOG(LogTemp, Warning, TEXT("Player has lose :("));
    }

    else
    {
        UE_LOG(LogTemp, Warning, TEXT("%s Player has Won ;)"), *GetName());
    }

}



void AEliminatorPlayerController::BeginPlay()
{
    Super::BeginPlay();

    UUserWidget *Hud = CreateWidget(this, PlayerHudClass);
    if(Hud != nullptr)
    {
        Hud->AddToViewport();
    }
}
