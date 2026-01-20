import QtQuick
import QtQuick.Window

Window {
    width: 400
    height: 300
    visible: true
    title: "Test"
    
    Rectangle {
        anchors.fill: parent
        color: "lightblue"
        
        Text {
            anchors.centerIn: parent
            text: "Hello World!"
            font.pixelSize: 32
        }
    }
}