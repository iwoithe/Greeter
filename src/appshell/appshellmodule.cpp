#include <QQmlEngine>

#include "appshellmodule.h"

using namespace gt::appshell;

static void appshell_init_resources()
{
    Q_INIT_RESOURCE(appshell);
}

std::string AppShellModule::moduleName() const
{
    return "appshell";
}

void AppShellModule::registerResources()
{
    appshell_init_resources();
}
