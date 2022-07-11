import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Greeter.AppShell 0.1
import Greeter.Greet 0.1

ApplicationWindow {
    id: root
    width: 800
    height: 600
    title: qsTr("Greeter")
    visible: true

    menuBar: MenuBar {
        id: menuBar
        Menu {
            id: fileMenu
            title: qsTr("File")

            Action {
                text: qsTr("Quit")
                onTriggered: Qt.quit()
            }
        }
        Menu {
            id: editMenu
            title: qsTr("Edit")

            Action {
                // TODO: Show or edit greeting settings?
                text: qsTr("Show greeting settings")
                onTriggered: AppShell.showGreetingSettings()
            }
        }
        Menu {
            id: helpMenu
            title: qsTr("Help")
            
            Action {
                text: qsTr("About")
                onTriggered: AppShell.about()
            }
            
            Action {
                text: qsTr("About Qt")
                onTriggered: AppShell.aboutQt()
            }
        }
    }

    GreetingView {
        id: greetingView
        anchors.fill: parent
    }
}
