#ifndef GT_ACTIONS_IDISPATCHER_H
#define GT_ACTIONS_IDISPATCHER_H

#include <functional>
#include <map>
#include <string>

#include "iactionscontroller.h"

namespace gt::actions
{
class IDispatcher
{
public:
    virtual void dispatch(std::string actionCode)
    {
        QVariantMap dummy;
        dispatch(actionCode, dummy);
    }
    virtual void dispatch(std::string actionCode, QVariantMap actionData) {}
    virtual void reg(IActionsController* actionsController, const std::string& actionCode, std::function<void(QVariantMap)> callback) {}
    virtual void unReg(IActionsController* actionController) {}
    virtual void unReg(IActionsController* actionController, std::string actionCode) {}
};
}

#endif
