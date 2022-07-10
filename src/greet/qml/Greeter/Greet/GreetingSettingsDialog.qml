import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Greeter.UiComponents 0.1

DialogView {
    id: root
    width: 300
    height: 150
    title: qsTr("Greeting Settings")

    property var greetingSettingsModel

    contentItem: Item {
        id: contentItem
        anchors.fill: parent
        ColumnLayout {
            anchors.fill: parent
            RowLayout {
                Layout.fillWidth: true
                Label {
                    text: qsTr("Greeting")
                }
                TextField {
                    id: greetingTextField
                    Layout.fillWidth: true
                    placeholderText: qsTr("The greeting")
                    text: greetingSettingsModel.greeting
                }
            }

            RowLayout {
                Layout.fillWidth: true
                Label {
                    text: qsTr("Name")
                }
                TextField {
                    id: nameTextField
                    Layout.fillWidth: true
                    placeholderText: qsTr("Your name")
                    text: greetingSettingsModel.name
                }
            }

            Item {
                Layout.fillHeight: true
            }
        }

        Button {
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            text: qsTr("Cancel")
            onClicked: root.close(1)
        }

        Button {
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            text: qsTr("Ok")
            onClicked: root.close({
                "code": 0,
                "greeting": greetingTextField.text,
                "name": nameTextField.text
            })
        }
    }
}
