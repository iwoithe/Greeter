import QtQuick 2.15
import QtQuick.Controls 2.15
import Greeter.Greet 0.1
import Greeter.Greet.Stores 0.1
import Greeter.UiComponents 0.1

Item {
    id: root

    GreetingStore {
        id: model
    }

    Label {
        anchors.centerIn: parent
        text: model.greeting + ", " + model.name;
    }

    Button {
        id: greetingSettingsButton
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 16
        text: qsTr("Greeting Settings")
        onClicked: {
            var result = greetingSettingsDialog.execRet()
            if (result["code"] == 0) {
                model.greeting = result["greeting"]
                model.name = result["name"]
            }
        }
    }

    // TODO: Should dialogs be opened from C++?
    GreetingSettingsDialog {
        id: greetingSettingsDialog
        greetingSettingsModel: model
    }
}
