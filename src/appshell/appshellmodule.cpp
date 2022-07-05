#include <QQmlEngine>

#include "appshellmodule.h"
#include "internal/appshellactionsstore.h"

using namespace gt::appshell;

static void appshellInitResources()
{
    Q_INIT_RESOURCE(appshell);
}

std::string AppShellModule::moduleName() const
{
    return "appshell";
}

void AppShellModule::registerResources()
{
    appshellInitResources();
}

void AppShellModule::registerStores()
{
    qmlRegisterSingletonInstance<AppShellActionsStore>("Greeter.AppShell", 0, 1, "AppShell", new AppShellActionsStore());
}
