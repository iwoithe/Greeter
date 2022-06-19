import QtQuick 2.15
import Greeter.Greet.Stores 0.1

Item {
    id: root
    Text {
        anchors.centerIn: parent
        text: GreetingStore.greeting + ", " + GreetingStore.name;
    }
}
