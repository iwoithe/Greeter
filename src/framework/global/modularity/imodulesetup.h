#ifndef GT_MODULARITY_IMODULESETUP_H
#define GT_MODULARITY_IMODULESETUP_H

#include <string>

namespace modularity {
class IModuleSetup
{
public:
    // virtual IModuleSetup();
    virtual ~IModuleSetup() {}
    virtual std::string moduleName() const = 0;
    virtual void registerResources() {}
    virtual void registerStores() {}
    virtual void registerUiTypes() {}
};
} // gt::modularity

#endif
