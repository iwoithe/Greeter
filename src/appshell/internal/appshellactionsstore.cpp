#include "appshellactionsstore.h"
#include "actions/dispatcher.h"

#include <QApplication>

using namespace gt::actions;
using namespace gt::appshell;

void AppShellActionsStore::init()
{
    dispatcher()->reg(this, "about-qt", [this](QVariantMap actionData) {this->aboutQt();});
}

void AppShellActionsStore::aboutQt()
{
    qApp->aboutQt();
}
