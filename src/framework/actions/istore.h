#ifndef GT_ACTIONS_ISTORE_H
#define GT_ACTIONS_ISTORE_H

#include "iactionscontroller.h"

namespace gt::actions
{
class IStore : public IActionsController
{
public:
    virtual ~IStore() {}
};
} // namespace gt::actions


#endif
