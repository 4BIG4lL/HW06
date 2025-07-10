#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class HW06_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* PlatformMesh;

    UPROPERTY(EditAnywhere, Category = "Movement")
    FVector MoveDirection = FVector(1, 0, 0);

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MoveSpeed = 200.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MaxRange = 500.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MovementInterval = 0.02f;

    FVector StartLocation;
    bool bMovingForward = true;

    FTimerHandle MovementTimerHandle;

    UFUNCTION()
    void MovePlatform();
};