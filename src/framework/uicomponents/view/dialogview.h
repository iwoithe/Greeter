#ifndef GT_UICOMPONENTS_DIALOGVIEW_H
#define GT_UICOMPONENTS_DIALOGVIEW_H

#include <QEventLoop>
#include <QObject>
#include <QQuickItem>
#include <QQuickView>
#include <QString>
#include <QVariantMap>

#include "global/ret.h"

using namespace gt;

namespace gt::uicomponents
{
// TODO: Inherit from popup view
class DialogView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQuickItem* parent READ parentItem WRITE setParentItem NOTIFY parentItemChanged)
    Q_PROPERTY(QQuickItem* contentItem READ contentItem WRITE setContentItem NOTIFY contentItemChanged)

    Q_PROPERTY(QVariantMap ret READ ret WRITE setRet NOTIFY retChanged)
    Q_PROPERTY(bool sync READ sync WRITE setSync NOTIFY syncChanged)
    
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
public:
    explicit DialogView(QQuickItem* parent = nullptr);
    ~DialogView() override = default;

    Q_INVOKABLE void close(const int& code);
    Q_INVOKABLE void close(const QVariantMap& ret);
    Q_INVOKABLE QVariantMap exec();
    Q_INVOKABLE void open();

    QQuickItem* parentItem() const;
    void setParentItem(QQuickItem* item);
    QQuickItem* contentItem() const;
    void setContentItem(QQuickItem* item);

    QVariantMap ret() const;
    void setRet(const QVariantMap& ret);

    bool sync() const;
    void setSync(const bool& sync);
    
    QString title() const;
    void setTitle(const QString& title);

    int width() const;
    void setWidth(const int& w);

    int height() const;
    void setHeight(const int& h);

private:
    QQuickItem* m_parentItem;
    QQuickItem* m_contentItem;

    QVariantMap m_ret;
    bool m_sync = false;

    QString m_title = QString("Dialog");
    int m_width = 800;
    int m_height = 600;

    QEventLoop m_loop;
    QQuickView* m_view;
signals:
    void parentItemChanged();
    void contentItemChanged();

    void retChanged();
    void syncChanged();

    void titleChanged();
    void widthChanged();
    void heightChanged();
};
} // namespace gt::uicomponents


#endif