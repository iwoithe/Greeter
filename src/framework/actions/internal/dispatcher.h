#ifndef GT_ACTIONS_DISPATCHER_H
#define GT_ACTIONS_DISPATCHER_H

#include <QVariantMap>

#include "../idispatcher.h"

namespace gt::actions
{
class Dispatcher : public IDispatcher
{
public:
    void dispatch(std::string actionCode, QVariantMap actionData) override;
    void reg(IActionsController* client, const std::string& actionCode, std::function<void(QVariantMap)> callback) override;
private:
    // TODO: Avoid using Qt classes here
    using Callbacks = std::map<std::string, std::function<void(QVariantMap)>>;
    using Clients = std::map<IActionsController*, Callbacks>;
    std::map<std::string, Clients> m_clients;
};
}

#endif
