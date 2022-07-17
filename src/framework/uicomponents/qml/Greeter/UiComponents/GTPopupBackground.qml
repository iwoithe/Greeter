import QtQuick 2.15

import Greeter.Ui 0.1
import Greeter.UiComponents 0.1

Item {
    id: root
    property var popupViewRoot: root.parent

    Canvas {
        id: arrow

        width: popupViewRoot.padding * 2
        height: popupViewRoot.padding

        enabled: popupViewRoot.showArrow
        visible: popupViewRoot.showArrow && arrow.height > 0

        x: popupViewRoot.arrowX - arrow.width / 2 - popupViewRoot.padding
        y: popupViewRoot.opensUpward ? parent.y + parent.height - height : 0

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)

            ctx.lineWidth = 2
            ctx.fillStyle = UiTheme.popupBackgroundColor
            ctx.strokeStyle = UiTheme.strokeColor

            ctx.beginPath()

            if (popupViewRoot.opensUpward) {
                ctx.moveTo(0, 0)
                ctx.lineTo(width / 2, height - 1)
                ctx.lineTo(width, 0)
            } else {
                ctx.moveTo(0, height)
                ctx.lineTo(width / 2, 1)
                ctx.lineTo(width, height)
            }

            ctx.stroke()
            ctx.fill()
        }
    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: arrow.height
        color: UiTheme.popupBackgroundColor
        border.width: 2
        border.color: UiTheme.strokeColor
    }
}
