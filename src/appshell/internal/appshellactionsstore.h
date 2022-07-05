#ifndef GT_APPSHELL_APPSHELLACTIONSSTORE
#define GT_APPSHELL_APPSHELLACTIONSSTORE

#include <QObject>
#include <QVariantMap>

#include "actions/istore.h"

using namespace gt::actions;

namespace gt::appshell
{
class AppShellActionsStore : public QObject, public IStore
{
    Q_OBJECT
public:
    AppShellActionsStore()
    {
        init();
    }

    void init() override;
    
    Q_INVOKABLE void aboutQt();
};
} // gt::greet

#endif
