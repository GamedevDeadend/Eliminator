
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerBase.generated.h"

UCLASS()
class ELIMINATOR_API APlayerBase : public ACharacter
{

	GENERATED_BODY()

private:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AGun> BlasterClass;

	UPROPERTY(EditAnywhere)
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

protected:

	virtual void BeginPlay() override;

public:	
	void DestroyPlayer();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void DelayFire();
};
