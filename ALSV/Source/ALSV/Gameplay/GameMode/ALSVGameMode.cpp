// Copyright Epic Games, Inc. All Rights Reserved.

#include "ALSVGameMode.h"
#include "Character/ALSVCharacter.h"
#include "UObject/ConstructorHelpers.h"

AALSVGameMode::AALSVGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
