#ifndef GT_ACTIONS_DISPATCHER_H
#define GT_ACTIONS_DISPATCHER_H

#include "internal/dispatcher.h"

using namespace gt::actions;

static Dispatcher* dis;

static void setDispatcher(Dispatcher* d)
{
    dis = d;
}

static Dispatcher* dispatcher()
{
    return dis;
}

#endif
