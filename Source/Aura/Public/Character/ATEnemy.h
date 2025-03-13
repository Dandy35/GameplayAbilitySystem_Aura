// Copyright Lazybolt Studios

#pragma once

#include "CoreMinimal.h"
#include "Character/ATCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "ATEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AATEnemy : public AATCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AATEnemy();
	
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
protected:
	virtual void BeginPlay() override;
};
