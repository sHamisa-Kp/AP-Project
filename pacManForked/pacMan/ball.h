#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Ball : public QGraphicsItem {
public:
    Ball();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setpoints(QVector <QPoint> points);

    void generatePointPixmap();

    QPixmap ballpix;
    QVector <QPoint> points;

};

#endif // BALL_H
