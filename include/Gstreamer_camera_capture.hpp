#pragma once

#include <gst/gst.h>

class Gstreamer_camera_capture
{

public:
    Gstreamer_camera_capture();
    ~Gstreamer_camera_capture();

private:
    GstElement* _pipeline;
    GstElement* _app_sink;
};
