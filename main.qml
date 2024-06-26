import QtQuick 2.0
import QtQuick.Controls 1.0
import CustomObjects 1.0

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("GUI application")

    property var refToStreamObj: stream_object
    Gui_stream_object {
        id: stream_object
        anchors.left: parent.left
        anchors.top: parent.top

        width: parent.width
        height: parent.height
    }

}
