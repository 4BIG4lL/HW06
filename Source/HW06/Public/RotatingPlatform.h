#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class HW06_API ARotatingPlatform : public AActor
{
    GENERATED_BODY()

public:
    ARotatingPlatform();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* PlatformMesh;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationInterval = 0.05f;

    UPROPERTY(EditAnywhere, Category = "Rotation")
    FRotator RotationAxis = FRotator(0, 1, 0);

    UPROPERTY(EditAnywhere, Category = "Rotation")
    float RotationSpeed = 3.0f;

    FTimerHandle RotationTimerHandle;

    UFUNCTION()
    void RotatePlatform();
};