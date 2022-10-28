// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/PABaseCharacter.h"

APABaseCharacter::APABaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void APABaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APABaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    //Set up "movement" bindings.
    PlayerInputComponent->BindAxis("MoveForward", this, &APABaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APABaseCharacter::MoveRight);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APABaseCharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &APABaseCharacter::StopJumping);

    //Set up "look" bindings.
    PlayerInputComponent->BindAxis("TurnAround", this, &APABaseCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APABaseCharacter::AddControllerPitchInput);
}

void APABaseCharacter::MoveForward(float Value)
{
    const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::X);
    AddMovementInput(Direction, Value);
}

void APABaseCharacter::MoveRight(float Value)
{
    const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}
