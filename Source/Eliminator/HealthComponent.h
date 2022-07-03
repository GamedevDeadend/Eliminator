
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ELIMINATOR_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

private:

	UFUNCTION()
	 void TakeDamage
	(	
		AActor* DamagedActor, float Damage,
	 	const class UDamageType* DamageType,
		class AController* InstigatedBy,AActor* DamageCauser
 	);


public:	

	UHealthComponent();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health Settings", meta = (AllowPrivateAccess = true))
	float Health = 300.0f;

};
