#ifndef PACMAN_H
#define PACMAN_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Pacman : public QGraphicsItem {

public:
    Pacman();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void advance();

    void setpacx(int);

    void setpacy(int);

    void setDirection(int dir);


    QPixmap left1, left2, left3;
    QPixmap up1, up2, up3;
    QPixmap down1, down2, down3;
    QPixmap right1, right2, right3;

    int pacx, pacy, x, y, height, width;
    int direction;
    int animestate;
};

#endif // PACMAN_H
