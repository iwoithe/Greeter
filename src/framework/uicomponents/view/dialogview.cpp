#include "dialogview.h"

#include <QApplication>
#include <QQuickView>
#include <QUrl>
#include <QWindow>

#include "global/engines.h"
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
    QQuickView *view = new QQuickView(qmlEngine(), nullptr);
    view->setSource(QUrl(":/qml/main.qml"));
    view->show();

    qApp->installEventFilter(this);
    // TODO: Add signals
}
