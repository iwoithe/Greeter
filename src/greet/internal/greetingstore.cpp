#include "greetingstore.h"

#include <QVariant>
#include <QDebug>

#include "actions/dispatcher.h"
#include "actions/actiontypes.h"
#include "interactive/internal/interactive.h"

using namespace gt::actions;
using namespace gt::greet;
using namespace gt::interactive;

void GreetingStore::init()
{
    Interactive::instance()->regDialog("qrc:/qml/Greeter/Greet/GreetingSettingsDialog.qml");

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

void GreetingStore::showGreetingSettings()
{
    Interactive::Params params = {{"sync", true},
                                  {"greetingSettingsModel", QVariant::fromValue(this)}};
    QVariantMap result = Interactive::instance()->openDialog("qrc:/qml/Greeter/Greet/GreetingSettingsDialog.qml", params);
    
    if (result["code"].toInt() != static_cast<int>(Ret::Code::Ok)) {
        return;
    }

    setGreeting(result["greeting"].toString());
    setName(result["name"].toString());
}
