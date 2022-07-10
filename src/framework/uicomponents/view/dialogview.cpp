#include "dialogview.h"

#include <QApplication>
#include <QQuickView>
#include <QUrl>
#include <QWindow>

// TODO: Remove engines.h
// #include "global/engines.h"
#include <QtQml>

using namespace gt::uicomponents;

DialogView::DialogView(QQuickItem* parent) : QObject(parent)
{
    setObjectName("PopupView");
    m_parentItem = parent;
}

void DialogView::close(const int& code)
{
    QVariantMap result = {{"code", code}};
    close(result);
}

void DialogView::close(const QVariantMap& ret)
{
    setRet(ret);

    if (m_loop.isRunning()) {
        m_loop.exit();
    }

    m_view->close();
}

QVariantMap DialogView::exec()
{
    // TODO: Fix "QEventLoop::exec: instance XXX has already called exec()"

    open();
    m_loop.exec();
    return m_ret;
}

void DialogView::open()
{
    m_view = new QQuickView(qmlEngine(this), nullptr);
    
    m_view->setTitle(m_title);
    m_view->setResizeMode(QQuickView::SizeRootObjectToView);
    m_view->setWidth(m_width);
    m_view->setHeight(m_height);
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

bool DialogView::sync() const
{
    return m_sync;
}

void DialogView::setSync(const bool& sync)
{
    if (m_sync == sync) {
        return;
    }

    m_sync = sync;
    emit syncChanged();
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

int DialogView::width() const
{
    return m_width;
}

void DialogView::setWidth(const int& w)
{
    if (m_width == w) {
        return;
    }

    m_width = w;
    emit widthChanged();
}

int DialogView::height() const
{
    return m_height;
}

void DialogView::setHeight(const int& h)
{
    if (m_height == h) {
        return;
    }

    m_height = h;
    emit heightChanged();
}
