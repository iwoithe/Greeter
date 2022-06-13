#ifndef GT_ACTIONS_IACTIONSDISPATCHER_H
#define GT_ACTIONS_IACTIONSDISPATCHER_H

#include <functional>

#include "actioncontroller.h"
#include "actiontypes.h"


namespace gt::actions {
class IActionsDispatcher
{
public:
    ~IActionsDispatcher() = default;

    using ActionCallBackWithData = std::function<void (const ActionData& actionData)>;
    using ActionCallBackWithNameAndData = std::function<void (const ActionCode&, const ActionData& actionData)>;

    virtual void dispatch(const ActionCode& actionCode) = 0;
    virtual void dispatch(const ActionCode& actionCode, const ActionData& actionData) = 0;

    virtual void unReg(ActionController* client) = 0;
    virtual void reg(ActionController* client, const ActionCode& actionCode, const ActionCallBackWithNameAndData& call) = 0;
};
}

#endif
