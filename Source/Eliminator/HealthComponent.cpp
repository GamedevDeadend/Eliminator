
#include "HealthComponent.h"
#include "GMB_Eliminator.h"
#include"PlayerBase.h"
#include"Kismet/GameplayStatics.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	// UE_LOG(LogTemp, Warning, TEXT("Health while constructor : %f"), Health);
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth;
	// UE_LOG(LogTemp, Warning, TEXT("Health at Begin Play : %f"), Health);
	AActor *Owner = GetOwner();
	if(Owner)
	{
		if( Health != 0)
		{Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);}	
	}
	
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
		if(Health == 0 && bCanIncrease == true)
		{
			APlayerBase *OurPlayer = Cast<APlayerBase>(UGameplayStatics::GetPlayerPawn(this, 0));
			OurPlayer->EnemiesKilled++;
			bCanIncrease = false;
		}

		AGMB_Eliminator *GameMode = GetWorld()->GetAuthGameMode<AGMB_Eliminator>();
		if(GameMode != nullptr)
		{
			GameMode->PawnKilled( Cast<APawn>(GetOwner()) );
		}
		
		// UE_LOG(LogTemp, Warning, TEXT("%s is dead"), *GetOwner()->GetName());
		return;
	}

	Health -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("Health at TakeDamage : %f"), Health);
}


// *******DEBUGGERS*********
// 	UE_LOG(LogTemp, Warning, TEXT("Health Reduced"));]
	// UE_LOG(LogTemp, Warning, TEXT("%s Player Is Dead %f"), *GetOwner()->GetName(), Health);

