// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Fire.h"
#include"AIController.h"
#include"PlayerBase.h"


UBTTask_Fire::UBTTask_Fire()
{
    NodeName = "Fire Task";
}

EBTNodeResult::Type UBTTask_Fire::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if(OwnerComp.GetAIOwner() == nullptr){  return EBTNodeResult::Failed;   }

        APlayerBase *Player = Cast<APlayerBase>(OwnerComp.GetAIOwner()->GetPawn());
    if(Player == nullptr)
    {return  return EBTNodeResult::Failed;}

    Player->Fire();


    return EBTNodeResult::Succeeded;

}
