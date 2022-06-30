// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class ELIMINATOR_API AGun : public AActor
{
	GENERATED_BODY()

private:

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon Defaults", meta = (AllowPrivateAccess = true));
		USceneComponent* WeaponRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon Defaults" ,meta = (AllowPrivateAccess = true));
		UStaticMeshComponent* Mesh;

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Defaults", meta = (AllowPrivateAccess = true));
	TSubclassOf<class ABullet> FiredBulletClass;
public:	
	// Sets default values for this actor's properties
	AGun();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon Defaults");
		USceneComponent* BulletSpawnPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Shoot();

};
