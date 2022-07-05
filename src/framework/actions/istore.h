#ifndef GT_ACTIONS_ISTORE_H
#define GT_ACTIONS_ISTORE_H

namespace gt::actions
{
class IStore
{
public:
    // TODO: Is there a better way instead of typing the following in every subclass?
    IStore()
    {
        init();
    }
    virtual ~IStore() {}
    virtual void init() {}
};
} // namespace gt::actions

#endif
