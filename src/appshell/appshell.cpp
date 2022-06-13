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

AppShell::run(int argc, char** argv)
{
    QApplication app(argc, argv);
    QQmlApplicationEngine* engine = new QQmlApplicationEngine();

    const QUrl url(QStringLiteral("qrc:/qml") + "/main.qml");
    engine->load(url);

    return app.exec();
}
