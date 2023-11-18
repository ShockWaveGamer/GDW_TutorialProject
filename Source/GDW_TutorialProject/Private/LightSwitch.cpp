// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"
#include "Components/SphereComponent.h" 
#include "Components/PointLightComponent.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don’t need it.
    PrimaryActorTick.bCanEverTick = true;
    DesiredIntensity = 3000.0f;

    PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
    PointLight1->Intensity = DesiredIntensity;
    PointLight1->SetVisibility(true);
    RootComponent = PointLight1;

    Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
    Sphere1->InitSphereRadius(250.0f);
    Sphere1->SetupAttachment(RootComponent);

    Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitch::OnOverlapBegin);
    // set up a notification for when this component overlaps something

    Sphere1->OnComponentEndOverlap.AddDynamic(this, &ALightSwitch::OnOverlapEnd);
    // set up a notification for when this component stops overlapping something
}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightSwitch::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && (OtherActor != this) && OtherComp)
    {
        ToggleLight();
    }
}

void ALightSwitch::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && (OtherActor != this) && OtherComp)
    {
        ToggleLight();
    }
}

void ALightSwitch::ToggleLight()
{
    PointLight1->ToggleVisibility();
}

