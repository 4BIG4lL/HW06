#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StageManager.generated.h"

UCLASS()
class HW06_API AStageManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AStageManager();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AActor> RotatingPlatformClass;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AActor> MovingPlatformClass;


	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 NumPlatformsToSpawn = 5;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	FVector SpawnAreaMin = FVector(-1000, -1000, 200);

	UPROPERTY(EditAnywhere, Category = "Spawn")
	FVector SpawnAreaMax = FVector(1000, 1000, 200);

	void SpawnPlatforms();
};
