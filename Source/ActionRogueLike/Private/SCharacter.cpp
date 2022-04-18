// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp ->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp ->SetupAttachment(SpringArmComp);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASCharacter::Move_Forward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);

}

void ASCharacter::Move_Right(float value)
{
	AddMovementInput(GetActorRightVector(), value);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move_forward", this, &ASCharacter::Move_Forward);
	PlayerInputComponent->BindAxis("Move_right", this, &ASCharacter::Move_Right);
	PlayerInputComponent->BindAxis("Look_Right", this, &APawn::AddControllerYawInput);
}

