#ifndef GT_ACTIONS_ACTIONSDISPATCHER_H
#define GT_ACTIONS_ACTIONSDISPATCHER_H

#include <map>

#include "../iactionsdispatcher.h"

namespace gt::actions
{
class ActionsDispatcher : public IActionsDispatcher
{
public:
    ActionsDispatcher() = default;
    ~ActionsDispatcher();

    void dispatch(const ActionCode& actionCode) override;
    void dispatch(const ActionCode& actionCode, const ActionData& actionData) override;

    void unReg(ActionController* client) override;
    void reg(ActionController* client, const ActionCode& actionCode, const ActionCallBackWithNameAndData& call) override;

private:
    using CallBacks = std::map<ActionCode, ActionCallBackWithNameAndData>;
    using Clients = std::map<ActionController*, CallBacks>;

    std::map<ActionCode, Clients> m_clients;
};
} // namespace gt::actions


#endif
