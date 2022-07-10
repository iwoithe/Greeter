#ifndef GT_INTERACTIVE_IINTERACTIVE_H
#define GT_INTERACTIVE_IINTERACTIVE_H

#include <any>
#include <map>
#include <string>
#include <variant>

#include <QVariant>

#include "global/ret.h"

using namespace gt;

namespace gt::interactive
{
class IInteractive
{
public:
    // TODO: Should std::any or std::variant be used?
    // using Values = std::variant<bool, int, float, double, std::string>;
    // using Params = std::map<std::string, Values>;
    // NOTE: Using a QVariant for now
    using Params = std::map<std::string, QVariant>;
    // using Params = std::map<std::string, std::any>;
    virtual void regDialog(const std::string& path) {}
    // TODO: Use Ret and Val instead of Qt types
    virtual QVariantMap openDialog(const std::string& path, Params& params) {return QVariantMap();}
};
} // gt::interactive

// Q_DECLARE_METATYPE(gt::interactive::IInteractive::Values);

#endif
