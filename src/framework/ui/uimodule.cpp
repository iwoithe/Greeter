#include "uimodule.h"

#include <QQmlEngine>

#include "uitheme.h"

using namespace gt::ui;

std::string UiModule::moduleName() const
{
    return "ui";
}

void UiModule::registerUiTypes()
{
    // TODO: Is ui.theme a better accesser in QML?
    qmlRegisterSingletonInstance<UiTheme>("Greeter.Ui", 0, 1, "UiTheme", new UiTheme());
}
