#include <QQmlEngine>

#include "greetmodule.h"

#include "internal/greetingstore.h"

using namespace gt::greet;

static void greet_init_resources()
{
    // Q_INIT_RESOURCE(appshell);
}

std::string GreetModule::moduleName() const
{
    return "greet";
}

void GreetModule::registerResources()
{
    greet_init_resources();
}

void GreetModule::registerStores()
{
    GreetingStore* greetingStore = new GreetingStore();
    qmlRegisterSingletonInstance("Greet.Stores", 0, 1, "GreetingStore", greetingStore);
}
