#ifndef GT_ACTIONS_ISTORE_H
#define GT_ACTIONS_ISTORE_H

namespace gt::actions
{
class IStore
{
public:
    IStore()
    {
        init();
    }
    virtual void init() {}
};
} // namespace gt::actions


#endif
