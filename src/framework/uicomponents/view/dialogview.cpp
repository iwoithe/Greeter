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
    if (m_loop.isRunning()) {
        m_loop.exit();
    }

    m_view->close();
}

void DialogView::close(const QVariantMap& ret)
{
    setRet(ret);

    if (m_loop.isRunning()) {
        m_loop.exit();
    }

    m_view->close();
}

void DialogView::exec()
{
    // TODO: Fix "QEventLoop::exec: instance XXX has already called exec()"

    open();
    m_loop.exec();
}

QVariantMap DialogView::execRet()
{
    open();
    m_loop.exec();
    // TODO: Convert to gt::Ret
    return m_ret;
}

void DialogView::open()
{
    m_view = new QQuickView(qmlEngine(this), nullptr);
    
    m_view->setTitle(m_title);
    m_view->setContent(QUrl(), nullptr, m_contentItem);
    m_view->show();

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

QVariantMap DialogView::ret() const
{
    return m_ret;
}

void DialogView::setRet(const QVariantMap& ret)
{
    if (m_ret == ret) {
        return;
    }

    m_ret = ret;
    emit retChanged();
}

QString DialogView::title() const
{
    return m_title;
}

void DialogView::setTitle(const QString& title)
{
    if (m_title == title) {
        return;
    }

    m_title = title;
    emit titleChanged();
}
