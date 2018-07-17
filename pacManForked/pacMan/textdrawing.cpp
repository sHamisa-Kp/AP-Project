#include "textdrawing.h"

TextDrawing::TextDrawing() {
    over = false;
    w = 350;
    h = 50;
    x = 450 / 2 - w / 2;
    y = 480 / 2 - h / 2;
    score = 0;
    playing = false;
    paused = false;

}

// setting locations on the screen for the writting
QRectF TextDrawing::boundingRect() const {
    return QRect(x, y, w, h);
}

// this method draws all the text at the beginning, during, end of the game.
void TextDrawing::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen(Qt::blue);
    painter->setPen(pen);
    QFont font = painter->font();


    if (!playing) {
        font.setPointSize(18);
        painter->setFont(font);


        if (over) {
            font.setPointSize(50);
            QPen pen(Qt::red);
            painter->setPen(pen);
            painter->setFont(font);
            painter->drawText(x, y - 100, "GAME OVER");

        } else {
            painter->setPen(Qt::red);
            painter->drawText(boundingRect(), Qt::AlignCenter, "SAY GO TO START");
            font.setPointSize(32);
            painter->setPen(Qt::yellow);
            painter->setFont(font);
            painter->drawText(x + 100, y - 180, "Pac Man");
        }


    }

    if (paused && !over) {
        font.setPointSize(15);
        painter->setFont(font);
        QPen pen(Qt::red);
        painter->setPen(pen);
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE\n (Say GO OR STOP)");
    }


}

