import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12

import MyLogger 1.0
import MyRectangle 1.0
import MyRectangleNamespace 1.0

ApplicationWindow {
    id: window
    title: "aula-2"
    visible: true
    height: 400
    width: 600

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    ColumnLayout {
        anchors.fill: parent
        MyRectangle {
            id: rectangle
            colorNS: MyRectangleNamespace.White
            Layout.fillHeight: true
            Layout.fillWidth: true
            Component.onCompleted: MyLogger.sayMyName()
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    print("mousearea !")
                    MyLogger.sayMyName()
                }
            }
        }
        ListView {
            Layout.minimumHeight: parent.height/5
            Layout.fillWidth: true
            clip: true
            onCountChanged: positionViewAtEnd()

            model: MyLogger.model
            delegate: Text {
                text: modelData
                color: "red"
            }
        }
    }
}
