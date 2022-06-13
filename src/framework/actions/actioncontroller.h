#ifndef GT_ACTIONS_ACTIONCONTROLLER_H
#define GT_ACTIONS_ACTIONCONTROLLER_H

#include "actiontypes.h"

namespace gt::actions
{
class IActionsDispatcher;
class ActionController
{
public:
    virtual ~ActionController()
    {
        if (m_dispatcher) {
            // TODO: Fix whatever needs to be fixed to run this (may require some macros)
            // WARNING: This WILL cause a segmentation fault/null pointer reference sometime in the future
            // m_dispatcher->unReg(this);
            setDispatcher(nullptr);
        }
    }

    virtual bool canReceiveAction(const ActionCode&) const {return true;}

    inline void setDispatcher(IActionsDispatcher* dispatcher)
    {
        m_dispatcher = dispatcher;
    }

private:
    IActionsDispatcher* m_dispatcher = nullptr;
};
} // namespace gt::actions

#endif
