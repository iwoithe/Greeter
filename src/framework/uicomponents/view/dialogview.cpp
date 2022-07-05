#include "dialogview.h"

#include <QApplication>
#include <QQuickView>
#include <QUrl>
#include <QWindow>

// TODO: Remove engines.h
// #include "global/engines.h"
#include <QtQml>
#include "global/ret.h"


using namespace gt::uicomponents;

DialogView::DialogView(QQuickItem* parent) : QObject(parent)
{
    setObjectName("PopupView");
}

void DialogView::close()
{

}

void DialogView::exec()
{
    open();
}

void DialogView::open()
{
    QQuickView *view = new QQuickView(qmlEngine(this), nullptr);
    view->setSource(QUrl("qrc:/qml/main.qml"));
    view->show();

    qApp->installEventFilter(this);
    // TODO: Add signals
}
