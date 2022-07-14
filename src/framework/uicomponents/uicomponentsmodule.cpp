#include "uicomponentsmodule.h"
#include "global/engines.h"

#include "view/dialogview.h"
#include "view/popupview.h"

using namespace gt::uicomponents;

static void uicomponentsInitResources()
{
    Q_INIT_RESOURCE(uicomponents);
}

std::string UiComponentsModule::moduleName() const
{
    return "uicomponents";
}

void UiComponentsModule::registerResources()
{
    uicomponentsInitResources();
}

void UiComponentsModule::registerUiTypes()
{
    qmlRegisterType<DialogView>("Greeter.UiComponents", 0, 1, "DialogView");
    qmlRegisterType<PopupView>("Greeter.UiComponents", 0, 1, "PopupView");
}
