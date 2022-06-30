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
	BulletMovement->MaxSpeed = DistanceTravelled;
	BulletMovement->InitialSpeed = DistanceTravelled;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super :: BeginPlay();
	BulletMesh->OnComponentHit.AddDynamic(this, &ABullet::OnHit);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ABullet :: OnHit(UPrimitiveComponent* HittingComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult)
{
	UE_LOG(LogTemp, Warning, TEXT("On Hit!! %s"), *OtherActor->GetName());
}

