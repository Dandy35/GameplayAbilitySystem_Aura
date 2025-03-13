// Copyright Lazybolt Studios


#include "UI/WidgetController/ATWidgetController.h"

void UATWidgetController::SetWidgetControllerParams(const FWigdetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UATWidgetController::BroadcastInitialValues()
{
	
}

void UATWidgetController::BindCallbacksToDependencies()
{
	
}
