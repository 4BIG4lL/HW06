#include "RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

ARotatingPlatform::ARotatingPlatform()
{
    PrimaryActorTick.bCanEverTick = false;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;
}

void ARotatingPlatform::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(
        RotationTimerHandle,
        this,
        &ARotatingPlatform::RotatePlatform,
        RotationInterval,
        true
    );
}

void ARotatingPlatform::RotatePlatform()
{
    FRotator NewRotation = GetActorRotation() + (RotationAxis * RotationSpeed);
    SetActorRotation(NewRotation);
}