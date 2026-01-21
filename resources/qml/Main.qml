import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: root
    width: 1400
    height: 800
    visible: true
    title: "MAVLink Inspector v0.1.0"

    Connections {
        target: mavlink
        function onMessageReceived(timestamp, type, content) {
            // 필터 체크
            if (messageFilter.shouldShowMessage(type)) {
                messageModel.append({
                    "timestamp": timestamp,
                    "type": type,
                    "content": content
                })
                messageList.positionViewAtEnd()
            }
        }
    }

    RowLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        // 왼쪽: 필터 패널
        GroupBox {
            title: "Message Filters"
            Layout.preferredWidth: 200
            Layout.fillHeight: true

            ColumnLayout {
                anchors.fill: parent
                spacing: 5

                CheckBox {
                    text: "Heartbeat"
                    checked: messageFilter.showHeartbeat
                    onCheckedChanged: messageFilter.showHeartbeat = checked
                }

                CheckBox {
                    text: "Attitude"
                    checked: messageFilter.showAttitude
                    onCheckedChanged: messageFilter.showAttitude = checked
                }

                CheckBox {
                    text: "Position"
                    checked: messageFilter.showPosition
                    onCheckedChanged: messageFilter.showPosition = checked
                }

                CheckBox {
                    text: "GPS"
                    checked: messageFilter.showGPS
                    onCheckedChanged: messageFilter.showGPS = checked
                }

                CheckBox {
                    text: "IMU"
                    checked: messageFilter.showIMU
                    onCheckedChanged: messageFilter.showIMU = checked
                }

                CheckBox {
                    text: "RC Channels"
                    checked: messageFilter.showRC
                    onCheckedChanged: messageFilter.showRC = checked
                }

                CheckBox {
                    text: "Commands"
                    checked: messageFilter.showCommand
                    onCheckedChanged: messageFilter.showCommand = checked
                }

                CheckBox {
                    text: "Other"
                    checked: messageFilter.showOther
                    onCheckedChanged: messageFilter.showOther = checked
                }

                Item { Layout.fillHeight: true }

                Button {
                    text: "Select All"
                    Layout.fillWidth: true
                    onClicked: messageFilter.selectAll()
                }

                Button {
                    text: "Clear All"
                    Layout.fillWidth: true
                    onClicked: messageFilter.clearAll()
                }

                Button {
                    text: "Clear Messages"
                    Layout.fillWidth: true
                    onClicked: messageModel.clear()
                }
            }
        }

        // 오른쪽: 메인 영역
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
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
                                Layout.preferredWidth: 200
                                font.family: "Consolas"
                                font.bold: true
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
}