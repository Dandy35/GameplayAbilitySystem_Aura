// Copyright Lazybolt Studios


#include "ATCharacterBase.h"

// Sets default values
AATCharacterBase::AATCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AATCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AATCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

