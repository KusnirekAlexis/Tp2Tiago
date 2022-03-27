// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tp2IaThiagoGameMode.h"
#include "Tp2IaThiagoPlayerController.h"
#include "Tp2IaThiagoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATp2IaThiagoGameMode::ATp2IaThiagoGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATp2IaThiagoPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}