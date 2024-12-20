#include "MyHud.h"
#include "AttributeWidget.h"

void AMyHud::Init()
{
	AttributeWidget = CreateWidget<UAttributeWidget>(GetOwningPlayerController(), AttributeWidgetClass);
	AttributeWidget->BindToAttributes();
	AttributeWidget->AddToViewport();
}
