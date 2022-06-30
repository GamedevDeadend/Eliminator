// Fill out your copyright notice in the Description page of Project Settings.

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

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta =(AllowPrivateAccess = true), Category = "Projectile Defaults" )
		class UProjectileMovementComponent* BulletMovement;

		float Damage = 30.0f;



	
public:	
	// Sets default values for this actor's properties
	ABullet();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HittingComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

		UPROPERTY(EditAnywhere)
		float DistanceTravelled = 5000.0f;

};
