#include "Gstreamer_camera_capture.hpp"

#include <iostream>

static GstFlowReturn new_sample(GstElement *sink, gpointer data) 
{
    GstSample *sample;

    // Retrieve the buffer
    g_signal_emit_by_name(sink, "pull-sample", &sample);
    if(sample) 
    {
        std::cout << "Frame captured!" << std::endl;
        gst_sample_unref(sample);
        return GST_FLOW_OK;
    }

    return GST_FLOW_ERROR;
}

Gstreamer_camera_capture::Gstreamer_camera_capture()
{
    // Build the pipeline
    this->_pipeline = gst_parse_launch("v4l2src device=/dev/video2 ! image/jpeg, width=1280, height=720 ! jpegdec ! appsink name=\"app_sink\"", NULL);

    // Get app sink part of pipeline
    this->_app_sink = gst_bin_get_by_name(GST_BIN(_pipeline), "app_sink");
    // Add handler to app sink
    g_object_set (this->_app_sink, "emit-signals", TRUE, NULL);
    g_signal_connect(this->_app_sink, "new-sample", G_CALLBACK(new_sample), this);

    // Start playing
    gst_element_set_state(_pipeline, GST_STATE_PLAYING);   
}

Gstreamer_camera_capture::~Gstreamer_camera_capture()
{
    gst_element_set_state(_pipeline, GST_STATE_NULL);
    gst_object_unref(_pipeline);
}
