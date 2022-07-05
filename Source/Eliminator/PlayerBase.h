
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerBase.generated.h"

UCLASS()
class ELIMINATOR_API APlayerBase : public ACharacter
{

	GENERATED_BODY()

private:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	int BulletFired = 0;
	

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AGun> BlasterClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	class UHealthComponent *HealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat Settings", meta = (AllowPrivateAccess = true))
	float ShootingDelay = 0.1f;

	UPROPERTY()
	class AGun* Gun;

	class APlayerController* PlayerControllerRef;

	FTimerHandle ShootTimer;

	void MoveForward(float axis);
	void MoveRight(float axis);
	void PlayerDead();
	void Fire();
	void SpawnEnemies();

public:

	APlayerBase();

	UFUNCTION(BlueprintCallable)
	bool IsDead() const;

	UFUNCTION(BlueprintCallable)
	float Health();
	UFUNCTION(BlueprintCallable)
	int BulletUsed();

	UFUNCTION(BlueprintCallable)
	int TotalEnemiesKilled();

protected:

	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	int EnemiesKilled = 0;
	
	UFUNCTION(BlueprintCallable)
	void DestroyPlayer();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void DelayFire();
};
