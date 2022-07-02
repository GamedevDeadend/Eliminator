// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearValue.h"
#include"BehaviorTree/BlackBoardComponent.h"


UBTTask_ClearValue::UBTTask_ClearValue()
{
    NodeName = "Clear BlackBoard Value";
}

EBTNodeResult::Type UBTTask_ClearValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask( OwnerComp, NodeMemory);

    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

    return EBTNodeResult::Succeeded;
    
}
