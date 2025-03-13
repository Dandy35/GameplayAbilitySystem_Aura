// Copyright Lazybolt Studios


#include "Character/ATEnemy.h"

#include "AbilitySystem/ATAbilitySystemComponent.h"
#include "AbilitySystem/ATAttributeSet.h"
#include "Aura/Aura.h"

AATEnemy::AATEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UATAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UATAttributeSet>("AttributeSet");
}

void AATEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AATEnemy::HighlightActor()
{
	//UE_LOG(LogTemp, Warning, TEXT("Highlight"));
	
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AATEnemy::UnHighlightActor()
{
	//UE_LOG(LogTemp, Warning, TEXT("UnHighlight"));

	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
