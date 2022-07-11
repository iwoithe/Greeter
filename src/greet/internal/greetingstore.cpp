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
    Interactive::instance()->regDialog("greeter://greet/greetingsettings", "qrc:/qml/Greeter/Greet/GreetingSettingsDialog.qml");

    // TODO: Should actionData be renamed to payload?
    dispatcher()->reg(this, "set-greeting", [this](QVariantMap actionData) {this->setGreeting(actionData["greeting"].toString());});
    dispatcher()->reg(this, "set-name", [this](QVariantMap actionData) {this->setName(actionData["name"].toString());});
    dispatcher()->reg(this, "greeting-settings", [this](QVariantMap actionData) {this->showGreetingSettings();});
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
    // TODO: Fix the following errors
    // - TypeError: Cannot read property 'greeting' of undefined
    // - TypeError: Cannot read property 'name' of undefined
    // Still works but would be good to fix
    Interactive::Params params = {{"sync", true},
                                  {"greetingSettingsModel", QVariant::fromValue(this)}};
    Interactive::Result result = Interactive::instance()->openDialog("greeter://greet/greetingsettings", params);
    
    if (result["code"].toInt() != static_cast<int>(Ret::Code::Ok)) {
        return;
    }

    setGreeting(result["greeting"].toString());
    setName(result["name"].toString());
}
