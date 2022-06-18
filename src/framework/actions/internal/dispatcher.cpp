#include "dispatcher.h"

using namespace gt::actions;

void Dispatcher::dispatch(std::string actionCode, QVariantMap actionData)
{
    auto actionIter = m_clients.find(actionCode);
    if (actionIter == m_clients.end()) {
        return;
    }

    const std::map<IActionsController*, std::map<std::string, std::function<void(QVariantMap)>>> clients = actionIter->second;
    for (auto clientIter = clients.begin(); clientIter != clients.end(); ++clientIter) {
        const IActionsController* actionsController = clientIter->first;
        const std::map<std::string, std::function<void(QVariantMap)>> callbacks = clientIter->second;
        auto a = callbacks.find(actionCode);
        if (a != callbacks.end()) {
            continue;
        }
        a->second(actionData);
    }
}

void Dispatcher::reg(IActionsController* client, const std::string& actionCode, std::function<void(QVariantMap)> callback)
{
    Clients& clients = m_clients[actionCode];
    Callbacks& callbacks = clients[client];
    callbacks.insert({actionCode, callback});
}
