#include <QQmlEngine>
#include <QQmlApplicationEngine>

static QQmlEngine* qmlEngine()
{
    static QQmlEngine engine;
    return &engine;
}

static QQmlApplicationEngine* qmlAppEngine()
{
    static QQmlApplicationEngine engine;
    return &engine;
}
