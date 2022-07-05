#include "greetingstore.h"

#include "actions/dispatcher.h"
#include "actions/actiontypes.h"

using namespace gt::actions;
using namespace gt::greet;

void GreetingStore::init()
{
    dispatcher()->reg(this, "set-greeting", [this](QVariantMap actionData) {this->setGreeting(actionData["greeting"].toString());});
    dispatcher()->reg(this, "set-name", [this](QVariantMap actionData) {this->setName(actionData["name"].toString());});
}

QString GreetingStore::greeting() const
{
    return m_greeting;
}

void GreetingStore::setGreeting(const QString& greeting)
{
    if (m_greeting == greeting) {
        return;
    }

    m_greeting = greeting;
    emit greetingChanged();
}

QString GreetingStore::name() const
{
    return m_name;
}

void GreetingStore::setName(const QString& name)
{
    if (m_name == name) {
        return;
    }

    m_name = name;
    emit nameChanged();
}
