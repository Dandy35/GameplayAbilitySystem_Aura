// Copyright Lazybolt Studios


#include "Character/ATCharacterBase.h"

AATCharacterBase::AATCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");

	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AATCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AATCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

