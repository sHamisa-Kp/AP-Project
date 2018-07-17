#include "ghost.h"

Ghost::Ghost() {
    animestate = 0;

    gosx = 450 / 2;
    gosy = 480 / 2;

    direction = 1;
    isScared = false;
    whiteb = false;

    pic.load(":/images/pinky.svg");
    scareb.load(":/images/ghostscaredblue1.svg");
    scareb1.load(":/images/ghostscaredblue2.svg");
    scarew.load(":/images/ghostscaredwhite1.svg");
    scarew1.load(":/images/ghostscaredwhite2.svg");

}

QRectF Ghost::boundingRect() const {
    return QRect(gosx - 15, gosy - 15, 20, 20);
}

void Ghost::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setOpacity(1); // makes the ghosts actually look like ghosts
    if (!isScared) {
        switch (direction) {
            case 1:
                if (animestate == 0) {
                    painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, pic);
                } else {
                    painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, pic);
                }
                break;
            case 4:
                if (animestate == 0) {
                    painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, pic);
                } else {
                    painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, pic);
                }
                break;
            case 3:
                if (animestate == 0) {
                    painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, pic);
                } else {
                    painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, pic);
                }
                break;
            case 2:
                if (animestate == 0) {
                    painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, pic);
                } else {
                    painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, pic);
                }
                break;
        }
    } else {
        if (whiteb) {
            if (animestate == 0) {
                painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, scareb);
            } else {
                painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, scarew1);
            }
        } else {
            if (animestate == 0) {
                painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, scareb);
            } else {
                painter->drawPixmap(gosx - 15, gosy - 15, 30, 30, scareb1);
            }
        }

    }

}

void Ghost::advance() {
    if (animestate > 2) {
        animestate = 0;
    } else {
        animestate++;
    }
}

void Ghost::setgosx(int x) {
    gosx = x;
}

void Ghost::setgosy(int y) {
    gosy = y;
}

void Ghost::setDirection(int dir) {
    direction = dir;
}

void Ghost::setColor(QString col) { // Because each ghost is different colours they need to be called differently
    if (col == "blue") {
        pic.load(":/images/inky.svg");
    } else if (col == "orange") {
        pic.load(":/images/clyde.svg");
    } else if (col == "red") {
        pic.load(":/images/blinky.svg");
    }
}
