#include <QApplication>
#include <QGuiApplication>
#include <QMetaType>
#include <QString>
#include <QStringLiteral>
#include <QUrl>
#include <QVariantMap>

#include "appshell.h"
#include "actions/dispatcher.h"

#include "global/engines.h"

using namespace gt::appshell;

AppShell::AppShell()
{
}

void AppShell::addModule(modularity::IModuleSetup* module)
{
    m_modules.push_back(module);
}

int AppShell::run(int argc, char** argv)
{
    QApplication app(argc, argv);

    for (modularity::IModuleSetup* m : m_modules) {
        m->registerResources();
        m->registerStores();
        m->registerUiTypes();
    }

    qmlAppEngine()->addImportPath(":/qml");

    const QUrl url(QStringLiteral("qrc:/qml") + "/main.qml");
    qmlAppEngine()->load(url);

    QVariantMap nameData;
    nameData["name"] = QString("Bob");
    dispatcher()->dispatch("set-name", nameData);

    int result = app.exec();

    qDeleteAll(m_modules);
    m_modules.clear();

    return result;
}
