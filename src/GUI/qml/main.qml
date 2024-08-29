import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

Window {
    id: mainWindow
    width: 1000
    height: 580
    minimumWidth: 800
    minimumHeight: 500
    visible: true
    color: "#000000"
    title: qsTr("GPL 3.0 CNute")

    flags: Qt.Window | Qt.FramelessWindowHint

    Rectangle {
        id: root
        color: "#2B2B2B"
        anchors.fill: parent

        GridLayout {
            id: grid
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            columns: 2
            rows: 2
            rowSpacing: 0
            columnSpacing: 0

            Rectangle {
                id: menuColumn
                color: "#232324"
                Layout.fillHeight: true
                Layout.preferredWidth: 50
                Layout.column: 0
                Layout.row: 0
                Layout.rowSpan: 2
                Layout.rightMargin: 5

                ColumnLayout {
                    anchors.topMargin: 10
                    anchors.top: parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 10

                    Rectangle {
                        id: projectTab
                        width: 30
                        height: 30
                        radius: 10
                        border.width: 0
                        color: "#303030"

                        Image {
                            id: projectTabIcon
                            width: 25
                            height: 25
                            source: "../../icons/dir.png"
                            anchors.centerIn: parent
                        }
                    }

                    Rectangle {
                        id: gitTab
                        width: 30
                        height: 30
                        radius: 10
                        border.width: 0
                        color: "#303030"

                        Image {
                            id: gitTabIcon
                            width: 25
                            height: 25
                            source: "../../icons/git.png"
                            anchors.centerIn: parent
                        }
                    }

                    Rectangle {
                        id: pluginTab
                        width: 30
                        height: 30
                        radius: 10
                        border.width: 0
                        color: "#303030"

                        Image {
                            id: pluginTabIcon
                            width: 25
                            height: 25
                            source: "../../icons/plugin.png"
                            anchors.centerIn: parent
                        }
                    }
                }
            }

            ColumnLayout {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.column: 1
                Layout.row: 0

                Rectangle {
                    id: headerProgramm
                    color: "#232324"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 32
                    Layout.bottomMargin: 5
                }
            }

            RowLayout {
                Layout.column: 1
                Layout.row: 1
                Layout.fillWidth: true
                Layout.fillHeight: true

                Rectangle {
                    id: explorerColumn
                    color: "#232324"
                    Layout.preferredWidth: 100
                    Layout.fillHeight: true
                }

                Rectangle {
                    id: codeArea
                    color: "#2B2B2B"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
            }
        }
    }
}
