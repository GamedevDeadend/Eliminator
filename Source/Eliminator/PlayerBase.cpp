
#include "PlayerBase.h"
#include "Gun.h"
#include "Eliminator/HealthComponent.h"
#include"TimerManager.h"
#include"GMB_Eliminator.h"
#include"Kismet/GameplayStatics.h"


APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	HealthComponent->Health = 300.0f;
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

		Gun = GetWorld()->SpawnActor<AGun>(BlasterClass);
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules :: KeepRelativeTransform, TEXT("WepaonSocket"));
		Gun->SetOwner(this);
	
		PlayerControllerRef = Cast<APlayerController>(GetController());
}


void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PlayerDead();
}


void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerBase::MoveRight);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &APlayerBase::DelayFire);
}

void APlayerBase :: MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayerBase :: MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayerBase::PlayerDead()
{
	if(HealthComponent == nullptr){return;}
	if (HealthComponent->Health <= 0)
		{
			if( GetName() != TEXT("BP_MainPlayer_C_0") )
			{
				DetachFromControllerPendingDestroy();
				if(Gun == nullptr)return;
				Gun->Destroy();
				FTimerHandle DestroyTimer;
				GetWorldTimerManager().SetTimer(DestroyTimer, this, &APlayerBase::DestroyPlayer, 4.0f, false);

			}

			else
			{
				if(Gun == nullptr)return;
				Gun->Destroy();	
			}
		}
}

void APlayerBase :: Fire()
{
		BulletFired++;
		Gun->Shoot();
}


void APlayerBase :: DelayFire()
{
	GetWorldTimerManager().SetTimer(ShootTimer, this, &APlayerBase::Fire, ShootingDelay, false);
}

bool APlayerBase :: IsDead() const
{
	bool bIsDead  = false;

	HealthComponent->Health == 0 ? bIsDead = true : bIsDead = false;

	return bIsDead;
}

float APlayerBase::Health()
{
	return (HealthComponent->Health/HealthComponent->MaxHealth);
}

int APlayerBase::BulletUsed()
{
	return BulletFired;
}

int APlayerBase::TotalEnemiesKilled()
{
	AGMB_Eliminator *GameMode = GetWorld()->GetAuthGameMode<AGMB_Eliminator>();
	GameMode->EnemiesKilledGM;
	return GameMode->EnemiesKilledGM;
}

void APlayerBase::DestroyPlayer()
{
	Destroy();
}

// ******DEBUGGERS***
 		// UE_LOG(LogTemp, Warning, TEXT("Fail"));
		// FHitResult HitResult;
		// PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel :: ECC_Visibility, false, HitResult);
	// UE_LOG(LogTemp, Warning, TEXT("Health : %f"), HealthComponent->Health);
	// UE_LOG(LogTemp, Warning, TEXT("%s Health : %f"), *GetName(), HealthComponent->Health);