#ifndef GT_ACTIONS_ACTIONTYPES_H
#define GT_ACTIONS_ACTIONTYPES_H

#include <QVariantMap>
#include <string>

#include "iactionsdispatcher.h"

namespace gt::actions
{
using ActionCode = std::string;
using ActionData = QVariantMap;
} // namespace gt::actions

#endif
