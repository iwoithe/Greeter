import QtQuick 2.15
import QtQuick.Controls 2.15

import Greeter.AppShell 0.1
import Greeter.Greet 0.1


MenuBar {
    id: root

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

        // TODO: Why does the menu stay open until the dialog is closed?
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