// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"

// Sets default values
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PARTICLE"));

	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));

	RootComponent = Body;
	Water->SetupAttachment(Body);
	Particle->SetupAttachment(Body);

	Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));
	Particle->SetRelativeLocation(FVector(0.0f, 0.0f, 155.0f));

	// 에셋 이름 중복 가능
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BODY(TEXT("/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01"));
	if (SM_BODY.Succeeded())
		Body->SetStaticMesh(SM_BODY.Object);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_WATER(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Meshes/Env/SM_Plains_Fountain_02.SM_Plains_Fountain_02"));
	if (SM_WATER.Succeeded())
		Water->SetStaticMesh(SM_WATER.Object);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS_PARTICLE(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_01.P_Water_Fountain_Splash_01"));
	if(PS_PARTICLE.Succeeded())
		Particle->SetTemplate(PS_PARTICLE.Object);

	RotateSpeed = 30.0f;
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	Super::BeginPlay();

	ABLOG_S(Warning);
	ABLOG(Warning, TEXT("Actor Name : %s"), *GetName());
}

void AFountain::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

// Called every frame
void AFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// (y, z, x)
	//AddActorLocalRotation(FRotator(0.0f, RotateSpeed*GetWorld()->GetDeltaSeconds(), 0.0f));

	Movement->RotationRate = FRotator(0.0f, RotateSpeed, 0.0f);
}

