import QtQuick 2.15
import QtQuick.Controls 2.15
import Greeter.Greet 0.1
import Greeter.Greet.Stores 0.1
import Greeter.UiComponents 0.1

Item {
    id: root
    Text {
        anchors.centerIn: parent
        text: GreetingStore.greeting + ", " + GreetingStore.name;
    }

    Button {
        id: greetingSettingsButton
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 16
        text: qsTr("Greeting Settings")
        onClicked: greetingSettingsDialog.exec()
    }

    GreetingSettingsDialog {
        id: greetingSettingsDialog
    }
}
