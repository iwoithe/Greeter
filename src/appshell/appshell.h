#ifndef GT_APPSHELL_APPSHELL_H
#define GT_APPSHELL_APPSHELL_H

#include <QList>

#include "modularity/imodulesetup.h"

namespace gt::appshell
{

class AppShell
{
public:
    AppShell();

    void addModule(modularity::IModuleSetup* module);

    int run(int argc, char** argv);
private:
    QList<modularity::IModuleSetup*> m_modules;
};

} // namespace gt::appshell

#endif
