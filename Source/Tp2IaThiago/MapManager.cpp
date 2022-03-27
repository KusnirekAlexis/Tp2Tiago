// Fill out your copyright notice in the Description page of Project Settings.

#include "MapManager.h"
#include "Mur.h"

#include <string>
#include <fstream>
#include <cerrno>

#include <Kismet/GameplayStatics.h>

// Sets default values
AMapManager::AMapManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMapManager::BeginPlay()
{
	Super::BeginPlay();

	std::string NomNiveau = TCHAR_TO_UTF8(*FPaths::ProjectDir());
	NomNiveau = NomNiveau + "/Content/Niveau/Niveau.txt";
	int ret = 0;

	std::ifstream niveau(NomNiveau);
	if (niveau.is_open())
	{
		std::string ligne;

		int y = 0;
		int x = 0;

		while (std::getline(niveau, ligne)) {
			y = 0;
			for (char elem : ligne) {
				if (elem == '0') {
					if (Mur) {
						FVector spawnLocation = FVector(this->GetActorLocation().X + x * 100, this->GetActorLocation().Y + y * 100, 100.f);
						FTransform spawn(GetActorRotation(), spawnLocation);
						GetWorld()->SpawnActor<AMur>(Mur, spawn);
					}
				}
				else if (elem == '2') {

					FVector spawnLocation = FVector(this->GetActorLocation().X + x * 100, this->GetActorLocation().Y + y * 100, 100.f);
					FTransform SpawnTransform(GetActorRotation(), spawnLocation);
					APlayerController* PC = UGameplayStatics::GetPlayerController(this, ret);
					APawn* Player = PC->GetPawn();
					if (PC)
					{
						//APawn* Player = PC->GetPawn();
						//GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Red, Player->GetName());

						Player->SetActorLocation(spawnLocation);
					}
					//ret++;
				}
				y++;
			}
			x++;
		}
		//PlaceCamera(x, y);
	}
	else {
		throw std::runtime_error("Fichier de niveau non disponible");
	}

	niveau.close();
}

void AMapManager::PlaceCamera(int x, int y)
{

	APlayerCameraManager* Camera = UGameplayStatics::GetPlayerCameraManager(this, 0);
	int ret;
	if (Camera) {
		if (x < y)
			ret = y;
		else
			ret = x;

		Camera->SetActorLocation(FVector(this->GetActorLocation().X + (x / 2) * 100, this->GetActorLocation().Y + (y / 2) * 100, ret * 100.f));
		Camera->SetActorRotation(FVector(0.f, 0.f, -90.f).Rotation());
		Camera->SetViewTarget(Camera);
	}
}

