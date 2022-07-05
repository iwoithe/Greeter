#include <QQmlEngine>
#include "greetmodule.h"

#include "internal/greetingstore.h"
#include "global/engines.h"

using namespace gt::greet;

static void greetInitResources()
{
    Q_INIT_RESOURCE(greet);
}

std::string GreetModule::moduleName() const
{
    return "greet";
}

void GreetModule::registerResources()
{
    greetInitResources();
}

void GreetModule::registerStores()
{
    qmlRegisterType<GreetingStore>("Greeter.Greet.Stores", 0, 1, "GreetingStore");
}
