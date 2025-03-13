// Copyright Lazybolt Studios

#pragma once

#include "CoreMinimal.h"

#include "Character/ATCharacterBase.h"

#include "ATCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AATCharacter : public AATCharacterBase
{
	GENERATED_BODY()
public:
	AATCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	UPROPERTY(EditAnywhere, Category= Camera)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category= Camera)
	class UCameraComponent* Camera;

	void InitAbilityActorInfo();

};
