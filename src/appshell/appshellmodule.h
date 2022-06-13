#ifndef GT_APPSHELL_APPSHELLMODULE_H
#define GT_APPSHELL_APPSHELLMODULE_H

#include "modularity/imodulesetup.h"

namespace gt::appshell
{
class AppShellModule : public modularity::IModuleSetup
{
public:
    std::string moduleName() const override;
    void registerResources() override;
    // void registerUiTypes() override;
};

} // namespace gt::appshell

#endif
