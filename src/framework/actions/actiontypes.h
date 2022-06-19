#ifndef GT_ACTIONS_ACTIONTYPES_H
#define GT_ACTIONS_ACTIONTYPES_H

#include <QVariantMap>
#include <string>

namespace gt::actions
{
using ActionCode = std::string;
using ActionData = QVariantMap;
using Method = std::function<void()>;
using MethodWithData = std::function<void(QVariantMap)>;
} // namespace gt::actions

#endif
