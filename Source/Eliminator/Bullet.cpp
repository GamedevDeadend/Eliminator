// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	SetRootComponent(BulletMesh);

	BulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Bullet Movement"));
	BulletMovement->InitialSpeed = 1000.0f;
	BulletMovement->MaxSpeed = 1000.0f;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	// FVector FireForce = FVector (FireForwardForce,0,0);
	// BulletMesh->AddForce(FireForce);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

