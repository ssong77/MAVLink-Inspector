import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: root
    width: 1200
    height: 800
    visible: true
    title: "MAVLink Inspector v0.1.0"

    // MAVLink 메시지 수신 처리
    Connections {
        target: mavlink
        function onMessageReceived(timestamp, type, content) {
            messageModel.append({
                "timestamp": timestamp,
                "type": type,
                "content": content
            })
            
            messageList.positionViewAtEnd()
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        // 상단: 연결 설정
        GroupBox {
            title: "Connection"
            Layout.fillWidth: true
            Layout.preferredHeight: 100

            RowLayout {
                anchors.fill: parent
                spacing: 10

                ComboBox {
                    id: connectionType
                    model: ["UDP", "Serial"]
                    Layout.preferredWidth: 100
                }

                TextField {
                    id: portField
                    placeholderText: "14550"
                    text: "14550"
                    Layout.preferredWidth: 100
                }

                Button {
                    id: connectButton
                    text: mavlink.connected ? "Disconnect" : "Connect"
                    onClicked: {
                        if (mavlink.connected) {
                            mavlink.disconnect()
                        } else {
                            var port = parseInt(portField.text) || 14550
                            mavlink.connectUDP(port)
                        }
                    }
                }

                Item { Layout.fillWidth: true }
            }
        }

        // 중간: 메시지 리스트
        GroupBox {
            title: "Messages"
            Layout.fillWidth: true
            Layout.fillHeight: true

            ListView {
                id: messageList
                anchors.fill: parent
                clip: true
                
                model: ListModel {
                    id: messageModel
                }

                delegate: ItemDelegate {
                    width: ListView.view.width
                    height: 30
                    
                    RowLayout {
                        anchors.fill: parent
                        anchors.leftMargin: 5
                        spacing: 10
                        
                        Text { 
                            text: model.timestamp 
                            Layout.preferredWidth: 100
                            font.family: "Consolas"
                        }
                        Text { 
                            text: model.type 
                            Layout.preferredWidth: 150
                            font.family: "Consolas"
                        }
                        Text { 
                            text: model.content 
                            Layout.fillWidth: true
                            font.family: "Consolas"
                        }
                    }
                }
            }
        }

        // 하단: 상태바
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            color: "#f0f0f0"
            
            Text {
                anchors.centerIn: parent
                text: mavlink.connected ? 
                      "Connected - Messages: " + mavlink.messageCount : 
                      "Ready"
            }
        }
    }
}