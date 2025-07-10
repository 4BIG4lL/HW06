#include "StageManager.h"
#include "Engine/World.h"

AStageManager::AStageManager()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AStageManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlatforms();
	
}

void AStageManager::SpawnPlatforms()
{
	if (!GetWorld())
	{
		return;
	}

	for (int32 i = 0; i < NumPlatformsToSpawn; ++i)
	{
		bool bSpawnRotating = FMath::RandBool();
		TSubclassOf < AActor > PlatformClass = bSpawnRotating ? RotatingPlatformClass : MovingPlatformClass;
		if (PlatformClass)
		{
			FVector RandomLocation = FVector(
				FMath::RandRange(SpawnAreaMin.X, SpawnAreaMax.X),
				FMath::RandRange(SpawnAreaMin.Y, SpawnAreaMax.Y),
				SpawnAreaMin.Z
			);
			FRotator SpawnRotation = FRotator::ZeroRotator;

			GetWorld()->SpawnActor<AActor>(PlatformClass, RandomLocation, SpawnRotation);
		}
	}
}

