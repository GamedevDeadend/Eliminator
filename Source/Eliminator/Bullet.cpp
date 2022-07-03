
#include "Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/DamageType.h"

ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = false;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	SetRootComponent(BulletMesh);

	BulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Bullet Movement"));
	BulletMovement->MaxSpeed = DistanceTravelled;
	BulletMovement->InitialSpeed = DistanceTravelled;
}


void ABullet::BeginPlay()
{
	Super :: BeginPlay();
	BulletMesh->OnComponentHit.AddDynamic(this, &ABullet::OnHit);
}

void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABullet :: OnHit(UPrimitiveComponent* HittingComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult)
{
	auto MyOwner = GetOwner();
	if(MyOwner == nullptr) return;

	auto MyOwnerInstigator = MyOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();

	if(OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics :: ApplyDamage(OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass);
		Destroy();
	}
}
// *****DEBUGGERS********
	// UE_LOG(LogTemp, Warning, TEXT("On Hit!! %s"), *OtherActor->GetName());
// 	UE_LOG(LogTemp, Warning, TEXT("null ptr test passed"), *OtherActor->GetName());