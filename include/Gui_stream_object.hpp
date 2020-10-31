#pragma once

#include <QQuickPaintedItem>
#include <QPainter>
#include <QImage>
//#include <QObject>

class Gui_stream_object : public QQuickPaintedItem
{
Q_OBJECT

public:
    Gui_stream_object(QQuickItem* parent = nullptr);
    ~Gui_stream_object();
    void paint(QPainter *painter) override;

public slots:
    void updateImage(const QImage&);

protected:
    QImage _m_image;
};
