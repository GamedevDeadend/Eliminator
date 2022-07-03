
#include "HealthComponent.h"
#include "GMB_Eliminator.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	// UE_LOG(LogTemp, Warning, TEXT("Health while constructor : %f"), Health);
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Health = 300.0f;
	// UE_LOG(LogTemp, Warning, TEXT("Health at Begin Play : %f"), Health);
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

	if(Damage <= 0.0f || Health <= 0.0f)
	{
		AGMB_Eliminator *GameMode = GetWorld()->GetAuthGameMode<AGMB_Eliminator>();
		if(GameMode != nullptr)
			{
				GameMode->PawnKilled( Cast<APawn>(GetOwner()) );
			}
		
		// UE_LOG(LogTemp, Warning, TEXT("%s is dead"), *GetOwner()->GetName());
		return;
	}

	Health -= Damage;
}


// *******DEBUGGERS*********
// 	UE_LOG(LogTemp, Warning, TEXT("Health Reduced"));]
	// UE_LOG(LogTemp, Warning, TEXT("%s Player Is Dead %f"), *GetOwner()->GetName(), Health);
	// UE_LOG(LogTemp, Warning, TEXT("Health at TakeDamage : %f"), Health);

