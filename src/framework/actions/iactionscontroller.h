#ifndef GT_ACTIONS_IACTIONSCONTROLLER_H
#define GT_ACTIONS_IACTIONSCONTROLLER_H

// TODO: Remove this class in favour of using only the store class

namespace gt::actions
{
class IActionsController
{
public:
    IActionsController()
    {
        init();
    }
    virtual ~IActionsController() {}

    virtual void init() {}
};
}

#endif
