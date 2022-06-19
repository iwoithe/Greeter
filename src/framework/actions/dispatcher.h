#ifndef GT_ACTIONS_DISPATCHER_H
#define GT_ACTIONS_DISPATCHER_H

#include "internal/dispatcher.h"

using namespace gt::actions;

static Dispatcher* dispatcher()
{
    static Dispatcher p;
    return &p;
}

#endif
