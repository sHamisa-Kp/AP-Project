#ifndef PACMANWINDOW_H
#define PACMANWINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "pacman.h"
#include "pacmanboard.h"
#include "ball.h"
#include "ghost.h"
#include "powerball.h"
#include "textdrawing.h"
#include <QShortcut>
#include <vector>

namespace Ui {
    class Pacmanwindow;
}

class Pacmanwindow : public QDialog {
    Q_OBJECT

public:

    explicit Pacmanwindow(QWidget *parent = 0);

    void pacmanMove();

    void ghostsMove(int i);

    void moveghostsInRect(int i);

    void checkLost();

    void startGame();

    void endGame();

    void pause();

    void retry();

    Pacman *pacman;
    Ghost *ghost[4];

    PacmanBoard *pacmanBoard;
    Ball *ball;
    PowerBall *powerball;
    TextDrawing *text;

    int pacX, pacY, direction, nextDirection;
    int ghostX[4], ghostY[4], ghostDir[4], nextGhostDir[4];

    bool moving, ghostMoving[4];
    bool scared;
    int score, state, lives;
    bool start; // the ghosts gate is now open
    bool ghostStart[4]; // a bool that helps the ghosts escape rectangle
    bool playing; // means a game is running
    bool isPaused;

    unsigned int paintTimeout = 70;
    unsigned int pacManTimeout = 140;
    unsigned int ghostTimeOut = pacManTimeout;

    QVector <QPoint> ballPoints; // this allows to set the location on screen
    QVector <QPoint> PowerballPoints;
    ~Pacmanwindow();

public slots:
    void updater();
    void ghostUpdater();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Pacmanwindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *ghostsTimer;
};

#endif // PACMANWINDOW_H
