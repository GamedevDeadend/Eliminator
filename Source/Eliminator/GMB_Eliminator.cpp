// Fill out your copyright notice in the Description page of Project Settings.


#include "GMB_Eliminator.h"
#include "EliminatorPlayerController.h"
#include"PlayerBase.h"
#include"EngineUtils.h"
#include"EnemyAI.h"
#include"Kismet/GameplayStatics.h"

AGMB_Eliminator::AGMB_Eliminator()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AGMB_Eliminator::BeginPlay()
{
    Super::BeginPlay();

    Temp = SpawnTimer;
}

void AGMB_Eliminator::Tick(float DeltaTime)
{
    Super :: Tick(DeltaTime);

    SpawnTimer -= DeltaTime;

    if(SpawnTimer < 0)
    {
        SpawnTimer = Temp;

        if(GetWorld() != nullptr)
        {

            if(EnemyBPClass != nullptr)
            {
                APawn *OurPlayer = UGameplayStatics::GetPlayerPawn(this, 0);
                FVector OurLocation = OurPlayer->GetActorLocation();
                SpawnLocation = OurLocation;
                SpawnLocation.X = OurLocation.X + FMath :: RandRange(-XRadius, XRadius);
                SpawnLocation.Y = OurLocation.Y + FMath :: RandRange(-YRadius, YRadius);
                APlayerBase *SpawnEnemy = GetWorld()->SpawnActor<APlayerBase>(EnemyBPClass, SpawnLocation, FRotator::ZeroRotator);
            }
        }
    }
}

void AGMB_Eliminator::PawnKilled(APawn *KilledPawn)
{
    // UE_LOG(LogTemp, Warning, TEXT("%s pawn was killed"), *KilledPawn->GetName());
    AEliminatorPlayerController *PlayerController = Cast<AEliminatorPlayerController>(KilledPawn->GetController());

    if(PlayerController != nullptr)
        {
            EndGame(false);
        }

    for(AEnemyAI* ControlledEnemy : TActorRange<AEnemyAI>(GetWorld()))
    {
        if(ControlledEnemy->IsAIDead() == false)
            {
                return;
            }
    }
        
    EndGame(true);
}

void AGMB_Eliminator::EndGame(bool bIsPlayerWinner)
{
    for( AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsPlayerController = Controller->IsPlayerController();
        if(bIsPlayerWinner)
        {
            Controller->GameHasEnded(Controller->GetPawn(), bIsPlayerController);
        }

        else
        {
            Controller->GameHasEnded(Controller->GetPawn(), !bIsPlayerController);
        }
    }
}

// **************DEBUGGERS******************
//         UE_LOG(LogTemp, Warning, TEXT("SUCESS 0"));
//                 UE_LOG(LogTemp, Warning, TEXT("SUCESS 0.1"));
//             UE_LOG(LogTemp, Warning, TEXT("SUCESS 0.2"));
//     UE_LOG(LogTemp, Warning, TEXT("SUCESS 0.3"));
//             UE_LOG(LogTemp, Warning, TEXT("SUCESS 1"));
//             UE_LOG(LogTemp, Warning, TEXT("SUCESS 2"));

