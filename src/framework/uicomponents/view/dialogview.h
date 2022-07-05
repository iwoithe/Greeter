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
public:
    explicit DialogView(QQuickItem* parent = nullptr);
    ~DialogView() override = default;

    Q_INVOKABLE void close();
    Q_INVOKABLE void exec();
    Q_INVOKABLE void open();
private:
    QEventLoop m_loop;
};
} // namespace gt::uicomponents


#endif