// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModes/PAGameModeBase.h"
#include "Character/PABaseCharacter.h"

APAGameModeBase::APAGameModeBase()
{
    DefaultPawnClass = APABaseCharacter::StaticClass();
}
