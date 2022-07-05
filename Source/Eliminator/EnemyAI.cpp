
#include "EnemyAI.h"
#include "Kismet/GamePlayStatics.h"
#include "PlayerBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include"Blueprint/UserWidget.h"
#include"GMB_Eliminator.h"



void AEnemyAI::BeginPlay()
{
    Super ::BeginPlay();

    PlayerPawn = UGameplayStatics :: GetPlayerPawn(GetWorld(), 0);
    if( AIBehavior != nullptr)
    {
        // if(GameMode == nullptr)return;
        RunBehaviorTree( AIBehavior);
        // GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GameMode->SpawnLocation);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), FVector(0.0f, 0.0f, 0.0f));
    }
}


void AEnemyAI::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if(LineOfSightTo(PlayerPawn))
    {
        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownLocation"), PlayerPawn->GetActorLocation());
    }
    else
    {
        GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    }
}

bool AEnemyAI::IsAIDead() const
{
    APlayerBase *ControlledAI = Cast<APlayerBase>(GetPawn());
    if(ControlledAI != nullptr)
    {
        return ControlledAI->IsDead();
    }

    return true;
}
// void AEnemyAI::BeginPlay()
// {
//     Super::BeginPlay();
//     if(AIBehavior != nullptr)
//     {
//         RunBehaviorTree(AIBehavior);
//     }
// }
// APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
// GetBlackboardComponent()->SetValueAsVector(TEXT("Start Coordinates"), GetPawn()->GetActorLocation());
// AGMB_Eliminator *GameMode = GetWorld()->GetAuthGameMode<AGMB_Eliminator>();
