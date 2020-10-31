#include <QApplication>

#include "Gui_application.hpp"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Gui_application gui_application;
    return app.exec();
}
