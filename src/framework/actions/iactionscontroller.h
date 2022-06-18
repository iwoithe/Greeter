#ifndef GT_ACTIONS_IACTIONSCONTROLLER_H
#define GT_ACTIONS_IACTIONSCONTROLLER_H

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
