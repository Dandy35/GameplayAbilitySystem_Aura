// Copyright Lazybolt Studios


#include "Player/ATPlayerState.h"

#include "AbilitySystem/ATAbilitySystemComponent.h"
#include "AbilitySystem/ATAttributeSet.h"

AATPlayerState::AATPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UATAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UATAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AATPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
