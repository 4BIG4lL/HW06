#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = false;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();

    GetWorld()->GetTimerManager().SetTimer(
        MovementTimerHandle,
        this,
        &AMovingPlatform::MovePlatform,
        MovementInterval,
        true
    );
}

void AMovingPlatform::MovePlatform()
{
    float DeltaTime = MovementInterval;
    FVector CurrentLocation = GetActorLocation();
    FVector Offset = MoveDirection.GetSafeNormal() * MoveSpeed * DeltaTime;

    if (bMovingForward)
    {
        CurrentLocation += Offset;
    }
    else
    {
        CurrentLocation -= Offset;
    }

    SetActorLocation(CurrentLocation);

    float DistanceTravelled = FVector::Dist(StartLocation, CurrentLocation);
    if (DistanceTravelled >= MaxRange)
    {
        bMovingForward = !bMovingForward;
    }
}