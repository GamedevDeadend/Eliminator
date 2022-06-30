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

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta =(AllowPrivateAccess = true), Category = "Projectile Defaults" )
		class UProjectileMovementComponent* BulletMovement;


	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

		UPROPERTY(EditAnywhere)
		float DistanceTravelled = 2000.0f;

};
