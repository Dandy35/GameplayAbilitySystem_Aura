// Copyright Lazybolt Studios


#include "UI/Widget/ATUserWidget.h"

void UATUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
