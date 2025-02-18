// Copyright Lazybolt Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ATCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AATCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AATCharacterBase();

protected:
	virtual void BeginPlay() override;


};
