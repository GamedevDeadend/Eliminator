
#include "PlayerBase.h"
#include "Gun.h"
#include "Eliminator/HealthComponent.h"
#include"TimerManager.h"



APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	HealthComponent->MaxHealth = 300.0f;
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
}


void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerBase::MoveRight);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter :: Jump);
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &APlayerBase :: DelayFire);
}

void APlayerBase :: MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayerBase :: MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayerBase :: Fire()
{
	if(PlayerControllerRef != nullptr)
	{
		Gun->Shoot();
	}
}

		// FHitResult HitResult;
		// PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel :: ECC_Visibility, false, HitResult);
void APlayerBase :: DelayFire()
{
	GetWorldTimerManager().SetTimer(ShootTimer, this, &APlayerBase::Fire, DelayBullet, false);
}

// ******DEBUGGERS***
// 		// UE_LOG(LogTemp, Warning, TEXT("Fail"));
		// UE_LOG(LogTemp, Warning, TEXT("Character Fired"));

