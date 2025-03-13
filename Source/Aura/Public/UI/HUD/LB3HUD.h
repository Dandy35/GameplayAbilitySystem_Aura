// Copyright Lazybolt Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LB3HUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
struct FWigdetControllerParams;
class UOverlayWidgetController;
class UATUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API ALB3HUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TObjectPtr<UATUserWidget> OverlayWidget;
	
	UOverlayWidgetController* GetOverlayWidgetController(const FWigdetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
protected:

	
private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UATUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	

};
