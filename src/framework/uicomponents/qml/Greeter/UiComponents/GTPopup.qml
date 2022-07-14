import QtQuick 2.15

import Greeter.UiComponents 0.1

PopupView {
    id: root

    contentItem: GTPopupBackground {
        id: contentContainer
        popupViewRoot: root
    }
}
