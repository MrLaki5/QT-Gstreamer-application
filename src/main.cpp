#include <QApplication>
#include <gst/gst.h>
#include <boost/program_options.hpp>
#include <iostream>

#include "Gui_application.hpp"

int main(int argc, char** argv)
{
    // Argument parser
    std::string camera_mount;
    boost::program_options::options_description desc("Allowed options");
    // Add argument parser options
    desc.add_options()
    ("help,h", "Print usage message")
    ("camera,c", boost::program_options::value(&camera_mount), "Path of camera mount");
    boost::program_options::variables_map vm;
    // Parse arguments
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    // Check if help is called or camera is not set
    if (vm.count("help") || vm.count("camera") == 0) {  
        std::cout << desc << std::endl;
        return 0;
    }
    // Load argument options
    camera_mount = vm["camera"].as<std::string>();
    std::cout << "Camera mount path: " << camera_mount << std::endl;
    
    // Start QT application
    QApplication app(argc, argv);
    gst_init (&argc, &argv);
    Gui_application gui_application;
    gui_application.init(camera_mount);
    return app.exec();
}
