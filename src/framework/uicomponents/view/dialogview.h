#ifndef GT_UICOMPONENTS_DIALOGVIEW_H
#define GT_UICOMPONENTS_DIALOGVIEW_H

#include <QEventLoop>
#include <QObject>
#include <QQuickItem>
#include <QString>

namespace gt::uicomponents
{
class DialogView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQuickItem* parent READ parentItem WRITE setParentItem NOTIFY parentItemChanged)
    Q_PROPERTY(QQuickItem* contentItem READ contentItem WRITE setContentItem NOTIFY contentItemChanged)

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
public:
    explicit DialogView(QQuickItem* parent = nullptr);
    ~DialogView() override = default;

    Q_INVOKABLE void close();
    Q_INVOKABLE void exec();
    Q_INVOKABLE void open();

    QQuickItem* parentItem() const;
    void setParentItem(QQuickItem* item);
    QQuickItem* contentItem() const;
    void setContentItem(QQuickItem* item);

    QString title() const;
    void setTitle(const QString& title);

private:
    QQuickItem* m_parentItem;
    QQuickItem* m_contentItem;

    QString m_title = QString("Dialog");

    QEventLoop m_loop;
signals:
    void parentItemChanged();
    void contentItemChanged();

    void titleChanged();
};
} // namespace gt::uicomponents


#endif