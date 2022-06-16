#include <QQmlEngine>

#include "greetmodule.h"

using namespace gt::greet;

static void appshell_init_resources()
{
    // Q_INIT_RESOURCE(appshell);
}

std::string GreetModule::moduleName() const
{
    return "greet";
}

void GreetModule::registerResources()
{
    appshell_init_resources();
}
