import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Greeter.UiComponents 0.1

// TODO: How to use QDesktopServices::setUrlHandler to open dialogs
DialogView {
    id: root
    width: 300
    height: 150
    title: qsTr("About")

    contentItem: Item {}
}
