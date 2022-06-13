#include <iostream>

#include "actionsdispatcher.h"

using namespace gt::actions;

ActionsDispatcher::~ActionsDispatcher()
{
    for (auto it = m_clients.begin(); it != m_clients.end(); ++it) {
        Clients& clients = it->second;
        for (auto cit = clients.begin(); cit != clients.end(); ++cit) {
            ActionController* client = cit->first;
            client->setDispatcher(nullptr);
        }
    }
}

void ActionsDispatcher::dispatch(const ActionCode& actionCode)
{
    static ActionData dummy;
    dispatch(actionCode, dummy);
}

void ActionsDispatcher::dispatch(const ActionCode& actionCode, const ActionData& actionData)
{
    auto it = m_clients.find(actionCode);
    if (it == m_clients.end()) {
        std::cout << "WARNING: Action '" << actionCode << "' is not registered" << std::endl;
        return;
    }

    const Clients& clients = it->second;
    for (auto cit = clients.cbegin(); cit != clients.cend(); ++cit) {
        const ActionController* client = cit->first;
        if (client->canReceiveAction(actionCode)) {
            const CallBacks& callBacks = cit->second;
            auto cbit = callBacks.find(actionCode);
            if (cbit != callBacks.end()) {
                continue;
            }

            const ActionCallBackWithNameAndData& callBack = cbit->second;
            callBack(actionCode, actionData);
        }
    }
}

void ActionsDispatcher::unReg(ActionController* client)
{
    for (auto it = m_clients.begin(); it != m_clients.end(); ++it) {
        Clients& clients = it->second;
        clients.erase(client);
    }

    client->setDispatcher(nullptr);
}

void ActionsDispatcher::reg(ActionController* client, const ActionCode& actionCode, const ActionCallBackWithNameAndData& call)
{
    client->setDispatcher(this);

    Clients& clients = m_clients[actionCode];
    CallBacks& callBacks = clients[client];
    callBacks.insert({actionCode, call});
}
