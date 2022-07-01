
#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	AActor *Owner = GetOwner();
	if(Owner)
	{	Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);	}
	
}


void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent :: TakeDamage(AActor *DamagedActor, float Damage, const UDamageType *DamageType,AController *Instigator, AActor *DamageCauser)
{
	if(Damage <= 0.0f &&  Health <= 0.0f) return;
	Health -= Damage;
}


// *******DEBUGGERS*********
// 	UE_LOG(LogTemp, Warning, TEXT("Health Reduced"));]
// 	UE_LOG(LogTemp, Warning, TEXT("Health : %f"), Health);

