#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>
#include <iostream>

#include <QQmlComponent>
#include <QString>
#include <QUrl>
#include <QVariant>

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

            for (auto& [ name, par ] : params) {
                // std::visit([name, dialog](auto&& c) {
                //     std::cout << c << std::endl;
                //     dialog->setProperty(name.c_str(), QVariant::fromValue(c);
                // }, par);
                dialog->setProperty(name.c_str(), par);
            }

            dialog->open();
        }
    }

    return Ret(Ret::Code::Ok);
}
