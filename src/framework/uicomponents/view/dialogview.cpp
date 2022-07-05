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
    m_parentItem = parent;
}

void DialogView::close()
{
    // TODO: How to use QEventLoop
    if (m_loop.isRunning()) {
        m_loop.exit();
    }
}

void DialogView::exec()
{
    open();
    m_loop.exec();
}

void DialogView::open()
{
    QQuickView *view = new QQuickView(qmlEngine(this), nullptr);

    view->setTitle("Test Dialog");

    view->setContent(QUrl(), nullptr, m_contentItem);

    view->show();

    qApp->installEventFilter(this);
    // TODO: Add signals
}

QQuickItem* DialogView::parentItem() const
{
    return m_contentItem;
}

void DialogView::setParentItem(QQuickItem* item)
{
    if (m_parentItem == item) {
        return;
    }

    m_parentItem = item;
    emit parentItemChanged();
}

QQuickItem* DialogView::contentItem() const
{
    return m_contentItem;
}

void DialogView::setContentItem(QQuickItem* item)
{
    if (m_contentItem == item) {
        return;
    }

    m_contentItem = item;
    emit contentItemChanged();
}
