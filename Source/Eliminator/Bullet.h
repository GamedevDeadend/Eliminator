
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class ELIMINATOR_API ABullet : public AActor
{
	GENERATED_BODY()

private:

UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta =(AllowPrivateAccess = true), Category = "Projectile Defaults" )
	class UStaticMeshComponent* BulletMesh;

UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true), Category = "Projectile Defaults" )
	class UProjectileMovementComponent* BulletMovement;

UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Bullet Settings", meta = (AllowPrivateAccess = true))
	float DistanceTravelled = 2000.0f;

UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Bullet Settings", meta = (AllowPrivateAccess = true))
	float Damage = 100.0f;

public:	

	ABullet();
	UFUNCTION()
	void OnHit
	(	
		UPrimitiveComponent* HittingComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse,
		 const FHitResult& HitResult
	);

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	
};
