#include "greetingstore.h"

#include "actions/dispatcher.h"
#include "actions/actiontypes.h"

using namespace gt::actions;
using namespace gt::greet;

void GreetingStore::init()
{
    // dispatcher()->reg(this, "set-greeting", &GreetingStore::setGreeting);
    dispatcher()->reg(this, "set-name", [this](QVariantMap actionData) {this->setName(actionData);});
}

QString GreetingStore::greeting() const
{
    return m_greeting;
}

void GreetingStore::setGreeting(QVariantMap actionData)
{
    m_greeting = actionData["greeting"].toString();
    emit greetingChanged();
}

QString GreetingStore::name() const
{
    return m_name;
}

void GreetingStore::setName(QVariantMap actionData)
{
    m_name = actionData["name"].toString();
    emit nameChanged();
}
