#include "appshellactionsstore.h"
#include "actions/dispatcher.h"
#include "interactive/internal/interactive.h"

#include <QApplication>

using namespace gt::actions;
using namespace gt::interactive;
using namespace gt::appshell;

void AppShellActionsStore::init()
{
    Interactive::instance()->regDialog("qrc:/qml/AboutDialog.qml");
    dispatcher()->reg(this, "about-qt", [this](QVariantMap actionData) {this->aboutQt();});
}

void AppShellActionsStore::about()
{
    Interactive::Params params = {{"sync", false}};
    Interactive::instance()->openDialog("qrc:/qml/AboutDialog.qml", params);
}

void AppShellActionsStore::aboutQt()
{
    qApp->aboutQt();
}
