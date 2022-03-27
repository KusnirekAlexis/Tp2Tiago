// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapManager.generated.h"

UCLASS()
class TP2IATHIAGO_API AMapManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMapManager();

	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly)
		TSubclassOf<class AMur> Mur;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PlaceCamera(int x, int y);
};
