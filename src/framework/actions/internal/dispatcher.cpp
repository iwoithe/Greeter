#include "dispatcher.h"

using namespace gt::actions;

void Dispatcher::dispatch(std::string actionCode, QVariantMap actionData)
{
    auto actionIter = m_clients.find(actionCode);
    if (actionIter == m_clients.end()) {
        return;
    }

    const Clients clients = actionIter->second;
    for (auto clientIter = clients.begin(); clientIter != clients.end(); ++clientIter) {
        const IActionsController* actionsController = clientIter->first;
        const Callbacks callbacks = clientIter->second;
        auto a = callbacks.find(actionCode);
        if (a != callbacks.end()) {
            continue;
        }
        a->second(actionData);
    }
}

void Dispatcher::reg(IActionsController* client, const std::string& actionCode, const MethodWithData& callback)
{
    Clients& clients = m_clients[actionCode];
    Callbacks& callbacks = clients[client];
    callbacks.insert({actionCode, callback});
}
