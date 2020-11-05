#include "Gstreamer_camera_capture.hpp"

#include <QImage>

static GstFlowReturn new_sample(GstElement *sink, gpointer data) 
{
    GstSample *sample;

    // Retrieve the buffer
    g_signal_emit_by_name(sink, "pull-sample", &sample);
    if(sample) 
    {
        GstBuffer* buffer = gst_sample_get_buffer(sample);
        GstMapInfo map;

        gst_buffer_map(buffer, &map, GST_MAP_READ);
        QImage test = QImage::fromData((const unsigned char*)map.data, map.size, "JPG");
        QImage* image = new QImage(test);
        reinterpret_cast<Gstreamer_camera_capture*>(data)->process_image(image);

        gst_buffer_unmap(buffer, &map);
        gst_sample_unref(sample);
        return GST_FLOW_OK;
    }

    return GST_FLOW_ERROR;
}

void Gstreamer_camera_capture::process_image(QImage* image)
{
    emit emit_image(image);
}

Gstreamer_camera_capture::Gstreamer_camera_capture()
{
    // Build the pipeline
    this->_pipeline = gst_parse_launch("v4l2src device=/dev/video2 ! image/jpeg, width=1280, height=720 ! appsink name=\"app_sink\"", NULL);

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
