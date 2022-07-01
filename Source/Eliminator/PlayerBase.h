
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

	UPROPERTY()
	class AGun* Gun;
	class APlayerController* PlayerControllerRef;
	FTimerHandle ShootTimer;

	void MoveForward(float axis);
	void Fire();
	void DelayFire();
	void MoveRight(float axis);

public:

	APlayerBase();
	UPROPERTY(EditAnywhere)
	float DelayBullet = 0.1f;

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
