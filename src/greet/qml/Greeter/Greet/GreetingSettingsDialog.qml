import QtQuick 2.15
import QtQuick.Controls 2.15
import Greeter.UiComponents 0.1

DialogView {
    id: root
    title: qsTr("Greeting Settings")
    contentItem: Item {
        id: contentItem
        Button {
            text: qsTr("Close with error")
            onClicked: {
                root.ret = {"code": -1}
                root.close()
            }
        }
    }
}
