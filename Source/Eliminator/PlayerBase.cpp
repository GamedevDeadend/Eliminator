// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"

// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move Forward"), this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Forward"), this, &APlayerBase::MoveRight);


}

void APlayerBase :: MoveForward(float axis)
{
	AddMovementInput(GetActorForwardVector() * axis);
}

void APlayerBase :: MoveRight(float axis)
{
	AddMovementInput(GetActorRightVector() * axis);
}


