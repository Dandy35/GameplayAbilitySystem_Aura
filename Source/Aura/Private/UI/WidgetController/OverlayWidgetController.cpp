// Copyright Lazybolt Studios


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/ATAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UATAttributeSet* LB3AttributeSet = Cast<UATAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(LB3AttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(LB3AttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(LB3AttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(LB3AttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UATAttributeSet* LB3AttributeSet = Cast<UATAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LB3AttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LB3AttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LB3AttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LB3AttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
