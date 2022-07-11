#include "appshellactionsstore.h"
#include "actions/dispatcher.h"
#include "interactive/internal/interactive.h"

#include <QApplication>

using namespace gt::actions;
using namespace gt::interactive;
using namespace gt::appshell;

void AppShellActionsStore::init()
{
    Interactive::instance()->regDialog("greeter://appshell/about", "qrc:/qml/Greeter/AppShell/AboutDialog.qml");
}

void AppShellActionsStore::about()
{
    Interactive::Params params;
    Interactive::instance()->openDialog("greeter://appshell/about", params);
}

void AppShellActionsStore::aboutQt()
{
    qApp->aboutQt();
}

void AppShellActionsStore::showGreetingSettings()
{
    dispatcher()->dispatch("greeting-settings", QVariantMap());
}
