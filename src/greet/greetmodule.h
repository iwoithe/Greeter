#ifndef GT_GREET_GREETMODULE_H
#define GT_GREET_GREETMODULE_H

#include "modularity/imodulesetup.h"

namespace gt::greet
{
class GreetModule : public modularity::IModuleSetup
{
public:
    std::string moduleName() const override;
    void registerResources() override;
    void registerStores() override;
    // void registerUiTypes() override;
};

} // namespace gt::greet

#endif
