#include "pacman.h"

Pacman::Pacman() {
    animestate = 0;
    pacx = 200;
    pacy = 360;
    x = 10;
    y = 10;
    height = 23;
    width = 23;
    direction = 4; //default direction of pacman

    right1.load(":/images/pacround.png");
    right2.load(":/images/pacright1.png");
    right3.load(":/images/pacright2.png");

    up1.load(":/images/pacround.png");
    up2.load(":/images/pacup1.png");
    up3.load(":/images/pacup2.png");

    down1.load(":/images/pacround.png");
    down2.load(":/images/pacdown1.png");
    down3.load(":/images/pacdown2.png");

    left1.load(":/images/pacround.png");
    left2.load(":/images/pacleft1.png");
    left3.load(":/images/pacleft2.png");

}

QRectF Pacman::boundingRect() const {
    return QRect(pacx-x, pacy-y, height, width);
}

/* set correct image to each direction */
void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    switch(direction) {
    case 1:
        if(animestate < 2) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,left1);
        }
        else if(animestate < 4) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,left2);
        }
        else if(animestate < 6) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,left3);
        }
        break;

    case 2:
        if(animestate < 2) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,up1);
        }
        else if(animestate < 4) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,up2);
        }
        else if(animestate < 6) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,up3);
        }
        break;

    case 3:
        if(animestate < 2) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,down1);
        }
        else if(animestate < 4) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,down2);
        }
        else if(animestate < 6) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,down3);
        }
        break;

    case 4:
        if(animestate < 2) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,right1);
        }
        else if(animestate < 4) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,right2);
        }
        else if(animestate < 6) {
            painter->drawPixmap(pacx-x,pacy-y,height,width,right3);
        }
        break;
    }
}


// a method used to animate pacman through the three images.
void Pacman::advance() {
    (animestate > 3) ? animestate = 0 : animestate++;
}
void Pacman::setpacx(int x) {
    pacx=x;
}

void Pacman::setpacy(int y) {
    pacy=y;
}

void Pacman::setDirection(int dir) {
    direction = dir;
}

void Pacman::setDeath(int d) {
    death=d;
}

