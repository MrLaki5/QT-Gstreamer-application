#include "Gui_application.hpp"

Gui_application::Gui_application()
{
    this->_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}