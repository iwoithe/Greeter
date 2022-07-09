#include <QQmlComponent>
#include <QUrl>
#include <QString>
#include "global/engines.h"
#include "uicomponents/view/dialogview.h"

#include "interactive.h"

using namespace gt::interactive;
using namespace gt::uicomponents;

Interactive* Interactive::instance()
{
    static Interactive i;
    return &i;
}

void Interactive::regDialog(const std::string& path)
{
    m_dialogs.push_back(path);
}

Ret Interactive::openDialog(const std::string& path, Params& params)
{
    for (std::string p : m_dialogs) {
        if (path == p) {
            QQmlComponent* component = new QQmlComponent(qmlAppEngine(), QUrl(QString::fromStdString(path)));
            DialogView* dialog = qobject_cast<DialogView*>(component->create());
            dialog->open();
        }
    }

    return Ret(Ret::Code::Ok);
}
