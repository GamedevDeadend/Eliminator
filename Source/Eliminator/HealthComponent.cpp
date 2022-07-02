
#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Health while constructor : %f"), Health);
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Health = 300.0f;
	UE_LOG(LogTemp, Warning, TEXT("Health at Begin Play : %f"), Health);
	AActor *Owner = GetOwner();
	if(Owner)
	{	Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);	}
	
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent :: TakeDamage
(	
	AActor *DamagedActor, float Damage,
	const UDamageType *DamageType,AController *Instigator,
	AActor *DamageCauser
)


{
	if(Damage <= 0.0f || Health <= 0.0f) return;
	Health -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("Health at TakeDamage : %f"), Health);
}


// *******DEBUGGERS*********
// 	UE_LOG(LogTemp, Warning, TEXT("Health Reduced"));]
	// UE_LOG(LogTemp, Warning, TEXT("%s Player Is Dead %f"), *GetOwner()->GetName(), Health);

