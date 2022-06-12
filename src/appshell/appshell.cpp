#include <QApplication>
#include <QGuiApplication>
#include <QMetaType>
#include <QQmlApplicationEngine>
#include <QStringLiteral>
#include <QUrl>
#include <QQmlEngine>

#include "appshell.h"

using namespace gt::appshell;

static void initAppShellResources()
{
    Q_INIT_RESOURCE(appshell);
}

AppShell::AppShell()
{
    initAppShellResources();
}

AppShell::run(int argc, char** argv)
{
    QApplication app(argc, argv);
    QQmlApplicationEngine* engine = new QQmlApplicationEngine();

    const QUrl url(QStringLiteral("qrc:/qml") + "/main.qml");
    engine->load(url);

    return app.exec();
}
