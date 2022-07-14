#ifndef GT_UICOMPONENTS_DIALOGVIEW_H
#define GT_UICOMPONENTS_DIALOGVIEW_H

#include "global/ret.h"

#include "popupview.h"

using namespace gt;

namespace gt::uicomponents
{
class DialogView : public PopupView
{
    Q_OBJECT
public:
    explicit DialogView(QQuickItem* parent = nullptr);
    ~DialogView() override = default;

    bool isDialog() const override;
};
} // namespace gt::uicomponents


#endif