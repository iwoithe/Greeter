import QtQuick 2.15
import QtQuick.Window 2.15
import Greet.Stores 0.1


Window {
    id: root
    width: 800
    height: 600
    title: qsTr("Greeter")
    visible: true

    Text {
        anchors.centerIn: parent
        text: GreetingStore.name;
    }
}