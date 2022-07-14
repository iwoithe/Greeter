#include "dialogview.h"

using namespace gt::uicomponents;

DialogView::DialogView(QQuickItem* parent) : PopupView(parent)
{
    setObjectName("DialogView");
}

bool DialogView::isDialog() const
{
    return true;
}
