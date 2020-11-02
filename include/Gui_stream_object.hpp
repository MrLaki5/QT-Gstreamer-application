#pragma once

#include <QQuickPaintedItem>
#include <QPainter>
#include <QImage>
#include <QObject>

#include "Gstreamer_camera_capture.hpp"

class Gui_stream_object : public QQuickPaintedItem
{
Q_OBJECT

public:
    Gui_stream_object(QQuickItem* parent = nullptr);
    ~Gui_stream_object();
    void paint(QPainter *painter) override;

public slots:
    void updateImage(QImage* image);

protected:
    QImage _m_image;
    Gstreamer_camera_capture gstreamer_camera_capture;
};
