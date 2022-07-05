#include "uicomponentsmodule.h"
#include "global/engines.h"

#include "view/dialogview.h"

using namespace gt::uicomponents;

std::string UiComponentsModule::moduleName() const
{
    return "uicomponents";
}

void UiComponentsModule::registerUiTypes()
{
    qmlRegisterType<DialogView>("Greeter.UiComponents", 0, 1, "DialogView");
}
