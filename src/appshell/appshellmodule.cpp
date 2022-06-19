#include <QQmlEngine>

#include "appshellmodule.h"

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
