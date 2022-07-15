#ifndef GT_UI_UIMODULE_H
#define GT_UI_UIMODULE_H

#include "modularity/imodulesetup.h"

namespace gt::ui
{
class UiModule : public modularity::IModuleSetup
{
public:
    std::string moduleName() const override;
    void registerUiTypes() override;
};
}

#endif
