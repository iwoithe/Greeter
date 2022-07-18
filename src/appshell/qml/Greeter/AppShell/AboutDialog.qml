import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import Greeter.UiComponents 0.1

GTDialog {
    id: root
    width: 300
    height: 150
    title: qsTr("About")

    contentItem: GTDialogBackground {
        ColumnLayout {
            anchors.fill: parent

            Label {
                Layout.alignment: Qt.AlignHCenter
                Layout.maximumWidth: root.width - (anchors.margins * 2)
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.family: "Inter"
                text: qsTr("Greeter")
            }

            Label {
                Layout.alignment: Qt.AlignHCenter
                Layout.maximumWidth: root.width - (anchors.margins * 2)
                horizontalAlignment: Text.AlignHCenter
                font.family: "Inter"
                text: qsTr("An app which greets the user")
            }

            Label {
                Layout.alignment: Qt.AlignHCenter
                Layout.maximumWidth: root.width - (anchors.margins * 2)
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                font.family: "Inter"
                text: qsTr("This app was made to learn how to make a Flux-like architecture using C++ and QML.")
            }

            Label {
                Layout.alignment: Qt.AlignHCenter
                Layout.maximumWidth: root.width - (anchors.margins * 2)
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                font.family: "Inter"
                text: qsTr("Greeter is released under the GNU General Public version 3 license.")
            }
        }
    }
}
