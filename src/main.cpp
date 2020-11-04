#include <QApplication>
#include <gst/gst.h>
#include <boost/program_options.hpp>

#include "Gui_application.hpp"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    gst_init (&argc, &argv);
    Gui_application gui_application;
    return app.exec();
}
