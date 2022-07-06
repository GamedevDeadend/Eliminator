
#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include"particles/ParticleSystem.h"
#include "Bullet.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	SetRootComponent(Mesh);

	BulletSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Bullet Spawn Point"));
	BulletSpawnPoint->SetupAttachment(Mesh);
}

void AGun::BeginPlay()
{
	Super::BeginPlay();
}

void AGun ::Tick(float DeltaTime)
{
	Super ::Tick(DeltaTime);
}

void AGun :: Shoot()
{
	if(BulletSpawnPoint != nullptr)
		{
			FVector Location = BulletSpawnPoint->GetComponentLocation();
			FRotator Rotation = BulletSpawnPoint->GetComponentRotation();
			if(GetWorld() != nullptr)
			{
				AActor *FiredBullet = GetWorld()->SpawnActor<ABullet>(FiredBulletClass, Location, Rotation);
				if(FiredBullet != nullptr){FiredBullet->SetOwner(GetOwner());}
			}
		}
}
