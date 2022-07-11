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

void Interactive::regDialog(const std::string& path, const std::string& resourcePath)
{
    m_dialogs.insert({path, resourcePath});
}

Interactive::Result Interactive::openDialog(const std::string& path, Params& params)
{
    Interactive::Result result;
    for (auto iter = m_dialogs.begin(); iter != m_dialogs.end(); ++iter) {
        std::string p = iter->first;
        std::string rp = iter->second;
        if (path == p) {
            QQmlComponent* component = new QQmlComponent(qmlAppEngine(), QUrl(QString::fromStdString(rp)));
            DialogView* dialog = qobject_cast<DialogView*>(component->create());

            for (auto& [ name, par ] : params) {
                // std::visit([name, dialog](auto&& c) {
                //     std::cout << c << std::endl;
                //     dialog->setProperty(name.c_str(), QVariant::fromValue(c);
                // }, par);
                dialog->setProperty(name.c_str(), par);
            }

            if (dialog->sync()) {
                result = dialog->exec();
            } else {
                dialog->open();
            }

            break;
        }
    }

    return result;
}
