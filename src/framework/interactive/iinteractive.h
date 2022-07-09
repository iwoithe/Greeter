#ifndef GT_INTERACTIVE_IINTERACTIVE_H
#define GT_INTERACTIVE_IINTERACTIVE_H

#include <any>
#include <map>
#include <string>

#include "global/ret.h"

using namespace gt;

namespace gt::interactive
{
class IInteractive
{
public:
    using Params = std::map<std::string, std::any>;
    virtual void regDialog(const std::string& path) {}
    virtual Ret openDialog(const std::string& path, Params& params) {return Ret(Ret::Code::Undefined);}
};
} // gt::interactive

#endif
