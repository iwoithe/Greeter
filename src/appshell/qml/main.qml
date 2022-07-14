import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Greeter.AppShell 0.1
import Greeter.Greet 0.1
import Greeter.UiComponents 0.1

ApplicationWindow {
    id: root
    width: 800
    height: 600
    title: qsTr("Greeter")
    visible: true

    menuBar: GTMenuBar {}

    Button {
        id: btn
        anchors.left: parent.left
        anchors.top: parent.top
        text: qsTr("Open Popup")
        onClicked: {
            var result = popupView.exec()
            console.log(result["string"])
        }

        GTPopup {
            id: popupView
            width: 200
            height: 300

            // TODO: Still not completely happy with this workflow
            contentItem: GTPopupBackground {
                id: popupRoot
                popupViewRoot: popupView
                Button {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    y: popupView.padding
                    text: qsTr("Some button")
                    onClicked: popupView.close({
                        "code": 0,
                        "string": "test"
                    })
                }
            }
        }
    }

    GreetingView {
        id: greetingView
        anchors.fill: parent
    }
}
