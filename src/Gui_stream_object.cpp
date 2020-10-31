#include "Gui_stream_object.hpp"

Gui_stream_object::Gui_stream_object(QQuickItem* parent): QQuickPaintedItem(parent)
{}

Gui_stream_object::~Gui_stream_object()
{}

void Gui_stream_object::updateImage(const QImage& image)
{
    this->_m_image = image;
    update();
}

void Gui_stream_object::paint(QPainter* painter)
{
    painter->drawImage(this->boundingRect(), this->_m_image);
}