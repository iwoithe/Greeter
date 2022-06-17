#include <QApplication>
#include <QGuiApplication>
#include <QMetaType>
#include <QQmlApplicationEngine>
#include <QStringLiteral>
#include <QUrl>

#include "appshell.h"

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

    QQmlApplicationEngine* engine = new QQmlApplicationEngine();

    const QUrl url(QStringLiteral("qrc:/qml") + "/main.qml");
    engine->load(url);

    return app.exec();
}
