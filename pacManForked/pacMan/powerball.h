#ifndef POWERBALL_H
#define POWERBALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class PowerBall : public QGraphicsItem {
public:
    PowerBall();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setpoints(QVector <QPoint> points);

    void generatePointPixmap();

    QVector <QPoint> points;
    QPixmap pBallPix;
};

#endif // POWERBALL_H
