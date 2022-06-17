#include "greetingstore.h"

using namespace gt::greet;

QString GreetingStore::greeting() const
{
    return m_greeting;
}

void GreetingStore::setGreeting(QString greeting)
{
    m_greeting = greeting;
    emit greetingChanged();
}

QString GreetingStore::name() const
{
    return m_name;
}

void GreetingStore::setName(QString name)
{
    m_name = name;
    emit nameChanged();
}
