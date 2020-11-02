#include "Gui_stream_object.hpp"

Gui_stream_object::Gui_stream_object(QQuickItem* parent): QQuickPaintedItem(parent)
{
    qRegisterMetaType<QImage*>("QImage*");
    connect(&(this->gstreamer_camera_capture), &Gstreamer_camera_capture::emit_image, this, &Gui_stream_object::updateImage, Qt::QueuedConnection);
    // TODO: Remove in some point, thisi is just test to see if image is drawn
    QImage image(400, 400, QImage::Format_RGB32);
    image.fill(Qt::red);
    this->_m_image = image;
}

Gui_stream_object::~Gui_stream_object()
{}

void Gui_stream_object::updateImage(QImage* image)
{
    this->_m_image = *image;
    delete image;
    update();
}

void Gui_stream_object::paint(QPainter* painter)
{
    painter->drawImage(this->boundingRect(), this->_m_image);
}