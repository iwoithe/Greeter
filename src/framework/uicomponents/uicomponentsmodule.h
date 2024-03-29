#ifndef GT_UICOMPONENTS_UICOMPONENTS_MODULE_H
#define GT_UICOMPONENTS_UICOMPONENTS_MODULE_H

#include "modularity/imodulesetup.h"

namespace gt::uicomponents
{
class UiComponentsModule : public modularity::IModuleSetup
{
public:
    std::string moduleName() const override;
    void registerResources() override;
    void registerUiTypes() override;
};
}

#endif