#ifndef GT_UICOMPONENTS_DIALOGVIEW_H
#define GT_UICOMPONENTS_DIALOGVIEW_H

#include <QEventLoop>
#include <QObject>
#include <QQuickItem>

namespace gt::uicomponents
{
class DialogView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQuickItem* parent READ parentItem WRITE setParentItem NOTIFY parentItemChanged)
    Q_PROPERTY(QQuickItem* contentItem READ contentItem WRITE setContentItem NOTIFY contentItemChanged)
public:
    explicit DialogView(QQuickItem* parent = nullptr);
    ~DialogView() override = default;

    QQuickItem* parentItem() const;
    void setParentItem(QQuickItem* item);

    QQuickItem* contentItem() const;
    void setContentItem(QQuickItem* item);

    Q_INVOKABLE void close();
    Q_INVOKABLE void exec();
    Q_INVOKABLE void open();
private:
    QQuickItem* m_parentItem;
    QQuickItem* m_contentItem;

    QEventLoop m_loop;
signals:
    void parentItemChanged();
    void contentItemChanged();
};
} // namespace gt::uicomponents


#endif