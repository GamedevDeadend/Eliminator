// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "Gun.h"
#include "DrawDebugHelpers.h"

// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

		Gun = GetWorld()->SpawnActor<AGun>(BlasterClass);
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules :: KeepRelativeTransform, TEXT("WepaonSocket"));
		Gun->SetOwner(this);
	
		PlayerControllerRef = Cast<APlayerController>(GetController());


}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerBase::MoveRight);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter :: Jump);
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &APlayerBase :: Fire);
	//PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
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
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel :: ECC_Visibility, false, HitResult);
		UE_LOG(LogTemp, Warning, TEXT("PASS"));
		Gun->Shoot();
	}
		UE_LOG(LogTemp, Warning, TEXT("Fail"));
}


