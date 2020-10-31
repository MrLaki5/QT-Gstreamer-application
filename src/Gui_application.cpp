#include "Gui_application.hpp"

Gui_application::Gui_application()
{
    qmlRegisterType<Gui_stream_object>("CustomObjects", 1, 0, "Gui_stream_object");
    this->_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}
