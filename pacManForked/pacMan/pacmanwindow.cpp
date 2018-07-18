
#include "pacmanwindow.h"
#include "ui_pacmanwindow.h"
#include <QThread>
#include <QtWidgets>
#include <iostream>

Pacmanwindow::Pacmanwindow(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Pacmanwindow) {

    // Setting up the ui
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    scene->setSceneRect(0, 0, 640, 480);
    ui->graphicsView->setSceneRect(scene->sceneRect());
    //Used to exit the application
//    connect(ui->exitButton, SIGNAL(clicked()), qApp, SLOT(closeAllWindows()));

    text = new TextDrawing;
    text->over = false;
    text->paused = false;
    scene->addItem(text);
    text->setZValue(7);// This allows it to be ontop of the graphic screen
}

// A Method used to start the game
void Pacmanwindow::startGame() {
    ghostX[0]= 450 / 2;
    ghostY[0]= 480 / 2;
    ghostX[1] = 450 / 2;
    ghostY[1] = 480 / 2;
    ghostX[2] = 450 / 2;
    ghostY[2] = 480 / 2;
    ghostX[3] = 450 / 2;
    ghostY[3] = 480 / 2;
    pacX = 200;
    pacY = 360;

    pacman = new Pacman;
    pacmanBoard = new PacmanBoard;
    ghost[0] = new Ghost;
    ghost[1] = new Ghost;
    ghost[2] = new Ghost;
    ghost[3] = new Ghost;
    ghost[1]->setColor("orange");
    ghost[2]->setColor("red");
    ghost[3]->setColor("blue");
    ball = new Ball; //sets the points for pacman
    powerball = new PowerBall;// powerballs to set ghosts to blue
    ballPoints = pacmanBoard->getballpoints();
    PowerballPoints = pacmanBoard->getpowerballpoints();

    scared = false;
    start = false;
    moving = false;
    isPaused = false;
    score = 0;
    direction = 0;
    playing = true;
    lives = 3;
    state = 0;

    scene->removeItem(text); // remove the startup text ofc
    scene->addItem(pacmanBoard);
    scene->addItem(pacman);
    scene->addItem(ghost[0]);
    scene->addItem(ghost[1]);
    scene->addItem(ghost[2]);
    scene->addItem(ghost[3]);
    scene->addItem(text);

    text->playing = true;
    ghostMoving[0] = false;
    ghostMoving[1] = false;
    ghostMoving[2] = false;
    ghostMoving[3] = false;
    moving = false;
    ghostStart[0] = false;
    ghostStart[1] = false;
    ghostStart[2] = false;
    ghostStart[3] = false;

    timer = new QTimer(this);
    ghostsTimer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updater()));
    connect(ghostsTimer, SIGNAL(timeout()), this, SLOT(ghostUpdater()));

    this->show();
    scene->update();
    this->update();

    timer->start(paintTimeout);
    ghostsTimer->start(ghostTimeOut);
    this->setFocus();
}

void Pacmanwindow::endGame() {
    timer->stop();
    ghostsTimer->stop();
    scene->removeItem(pacman);
    scene->removeItem(ghost[0]);
    scene->removeItem(ghost[1]);
    scene->removeItem(ghost[2]);
    scene->removeItem(ghost[3]);
    scene->removeItem(pacmanBoard);

    text->over = true;
    text->playing = false;
    start = false;
    playing = false;
    this->show();
    scene->update();
    this->update();
}

// This code is used when one of the livess are taken.
void Pacmanwindow::retry() {
    ghostX[0]= 450 / 2;
    ghostY[0]= 480 / 2;
    ghostX[1] = 450 / 2;
    ghostY[1] = 480 / 2;
    ghostX[2] = 450 / 2;
    ghostY[2] = 480 / 2;
    ghostX[3] = 450 / 2;
    ghostY[3] = 480 / 2;
    pacX = 400 / 2;
    pacY = 360;
    direction = 4;
    start = true;
    ghostStart[0] = false;
    ghostStart[1] = false;
    ghostStart[2] = false;
    ghostStart[3] = false;
    ghostMoving[0] = false;
    ghostMoving[1] = false;
    ghostMoving[2] = false;
    ghostMoving[3] = false;
    moving = false;
    state = 0;
}

// Method for pacmans movenment and wall collisions etc..
void Pacmanwindow::pacmanMove() {
    QPoint p;
    // New direction
    if (nextDirection != direction) {
        switch (nextDirection) {
            //  moving left...Whilst moving
            case 1:
                p.setX(pacX - 5);
                p.setY(pacY);
                if (pacmanBoard->canmove(p)) {
                    direction = nextDirection;
                    nextDirection = 0;
                }

                break;
                // moving right...whilst already moving
            case 4:
                p.setX(pacX + 5);
                p.setY(pacY);
                if (pacmanBoard->canmove(p)) {
                    direction = nextDirection;
                    nextDirection = 0;

                }
                // moving down
                break;
            case 3:
                p.setX(pacX);
                p.setY(pacY + 5);
                if (pacmanBoard->canmove(p)) {
                    direction = nextDirection;
                    nextDirection = 0;

                }
                // moving up
                break;
            case 2:
                p.setX(pacX);
                p.setY(pacY - 5);
                if (pacmanBoard->canmove(p)) {
                    direction = nextDirection;
                    nextDirection = 0;

                }
                break;
        }

    }

    // Move PacMan
    switch(direction) {
        case 1:
            p.setX(pacX - 5);
            p.setY(pacY);
            pacman->setDirection(direction);

            if (pacmanBoard->canmove(p)) {
                pacX -= 5;
                moving = true;

            } else {
                moving = false;
            }

            break;
        case 4:
            pacman->setDirection(direction);
            p.setX(pacX + 5);
            p.setY(pacY);
            if (pacmanBoard->canmove(p)) {
                pacX += 5;

                moving = true;

            } else {
                moving = false;
            }
            break;
        case 3:
            pacman->setDirection(direction);
            p.setX(pacX);
            p.setY(pacY + 5);
            if (pacmanBoard->canmove(p)) {
                pacY += 5;
                moving = true;
            } else {
                moving = false;
            }
            break;
        case 2:
            pacman->setDirection(direction);
            p.setX(pacX);
            p.setY(pacY - 5);
            if (pacmanBoard->canmove(p)) {
                pacY -= 5;
                moving = true;

            } else {
                moving = false;
            }
            break;
    }

    // this is so pacman can teleport through the side ports
    if (pacX <= 0) {
        pacX = 450;
        pacY = 230;
    } else if (pacX >= 450) {
        pacX = 0;
        pacY = 230;
    }

    pacman->setpacx(pacX);
    pacman->setpacy(pacY);
}

// moving ghosts around the map
void Pacmanwindow::ghostsMove(int i) {
    QPoint p;
    if (!ghostMoving[i]) {
        // When the ghost hits a wall or can't move give them a random dirrection.
        ghostDir[i] = (qrand() % 4) + 1;
    } else {
        //Changing direction dependant on where pacman is located
//        int deltaY = pacY - ghostY[i];
//        int deltaX = pacX - ghostX[i];
        if(!ghost[i]->isScared) {
            if (ghostDir[i] == 1 && ghostY[i] > pacY) {
                nextGhostDir[i] = 2;
            } else if (ghostDir[i] == 4 && ghostY[i] < pacY) {
                nextGhostDir[i] = 3;
            } else if (ghostDir[i] == 2 && ghostX[i] > pacX) {
                nextGhostDir[i] = 1;
            } else if (ghostDir[i] == 3 && ghostX[i] < pacX) {
                nextGhostDir[i] = 4;
            }
        } else {
            if (ghostDir[i] == 1 && ghostY[i] > pacY) {
                nextGhostDir[i] = 4;
            } else if (ghostDir[i] == 4 && ghostY[i] < pacY) {
                nextGhostDir[i] = 1;
            } else if (ghostDir[i] == 2 && ghostX[i] > pacX) {
                nextGhostDir[i] = 3;
            } else if (ghostDir[i] == 3 && ghostX[i] < pacX) {
                nextGhostDir[i] = 2;
            }
        }

    }

    if (nextGhostDir[i] != ghostDir[i]) {
        switch (nextGhostDir[i]) {
            case 1:
                p.setX(ghostX[i]- 5);
                p.setY(ghostY[i]);

                if (pacmanBoard->canmove(p)) {
                    ghostDir[i] = nextGhostDir[i];
                    nextGhostDir[i] = 0;
                }
                break;

            case 4:
                p.setX(ghostX[i]+ 5);
                p.setY(ghostY[i]);
                if (pacmanBoard->canmove(p)) {
                    ghostDir[i] = nextGhostDir[i];
                    nextGhostDir[i] = 0;
                }
                break;

            case 3:
                p.setX(ghostX[i]);
                p.setY(ghostY[i]+ 5);
                if (pacmanBoard->canmove(p)) {
                    ghostDir[i] = nextGhostDir[i];
                    nextGhostDir[i] = 0;

                }

                break;
            case 2:
                p.setX(ghostX[i]);
                p.setY(ghostY[i]- 5);
                if (pacmanBoard->canmove(p)) {
                    ghostDir[i] = nextGhostDir[i];
                    nextGhostDir[i] = 0;
                }
                break;
        }
    }

    switch(ghostDir[i]) {
        case 1:
            p.setX(ghostX[i]- 5);
            p.setY(ghostY[i]);
            ghost[i]->setDirection(ghostDir[i]);

            if (pacmanBoard->canmove(p)) {
                ghostX[i]-= 5;
                ghostMoving[i] = true;

            } else {
                ghostMoving[i] = false;
            }
            break;

        case 4:
            ghost[i]->setDirection(ghostDir[i]);
            p.setX(ghostX[i]+ 5);
            p.setY(ghostY[i]);
            if (pacmanBoard->canmove(p)) {
                ghostX[i]+= 5;

                ghostMoving[i] = true;

            } else {
                ghostMoving[i] = false;
            }

            break;
        case 3:
            ghost[i]->setDirection(ghostDir[i]);
            p.setX(ghostX[i]);
            p.setY(ghostY[i]+ 5);
            if (pacmanBoard->canmove(p)) {
                ghostY[i]+= 5;
                ghostMoving[i] = true;

            } else {
                ghostMoving[i] = false;
            }

            break;
        case 2:
            ghost[i]->setDirection(ghostDir[i]);
            p.setX(ghostX[i]);
            p.setY(ghostY[i]- 5);
            if (pacmanBoard->canmove(p)) {
                ghostY[i]-= 5;
                ghostMoving[i] = true;

            } else {
                ghostMoving[i] = false;
            }

            break;
    }

    if (ghostX[i]== 0) {
        ghostX[i]= 450;
        ghostY[i]= 230;
    } else if (ghostX[i]== 450) {
        ghostX[i]= 0;
        ghostY[i]= 230;
    }

    ghost[i]->setgosx(ghostX[i]);
    ghost[i]->setgosy(ghostY[i]);

}

// Keep ghosts in rectangles
void Pacmanwindow::moveghostsInRect(int i) {
    if (ghostX[i]== 450 / 2 + 40 || ghostX[i]== 450 / 2 - 40) {
        if (ghostDir[i] == 4) {
            ghostDir[i] = 1;
        } else {
            ghostDir[i] = 4;
        }
    }
    if (ghostDir[i] == 4) {

        ghostX[i]+= 5;

    } else {

        ghostX[i]-= 5;
    }


    ghost[i]->setgosx(ghostX[i]);
    ghost[i]->setgosy(ghostY[i]);
}

// This method is used to check for collisions with the ghosts and balls
void Pacmanwindow::checkLost() // lost the game
{
    // When all the points have been eaten start new game
    if(ballPoints.isEmpty()) {
        startGame();
    }

    // Checks for collisons between pacman and ghost
    for(int i = 0; i < 4; i++) {
        if (pacman->collidesWithItem(ghost[i])) {
            if(ghost[i]->isScared) {
//                std::cout << "I am scared" << std::endl;
                ghostX[i]= 450 / 2;
                ghost[i]->setgosx(ghostX[i]);
                ghostY[i]= 450 / 2;
                ghost[i]->setgosx(ghostX[i]);
                ghost[i]->isScared = false;
                ghost[i]->whiteb = false;
                ghostStart[i] = false;
                score += 100;
            }
            else {
//                std::cout << "I am not scared" << std::endl;
                scared = false;
                //FOR
                ghost[0]->isScared = false;
                ghost[1]->isScared = false;
                ghost[2]->isScared = false;
                ghost[3]->isScared = false;
                ghost[0]->whiteb = false;
                ghost[1]->whiteb = false;
                ghost[2]->whiteb = false;
                ghost[3]->whiteb = false;
                if (lives > 0) {
                    lives -= 1;
                    retry();
                    break;
                } else {
                    scene->addItem(text);
                    endGame();

                }
            }
        }
    }
}

void Pacmanwindow::keyPressEvent(QKeyEvent *event) {
    // Pressing space will start the game
    if (event->key() == Qt::Key_Space) {
        if (!playing) {
            startGame();
            playing = true;
        }
    }

    if (ghostX[3] == 450 / 2) { // if the ghost is in the rectangle keep adding
        start = true;
    }

    if(start) {
        switch (event->key()) {
            case Qt::Key_Left:
                if (!moving) {
                    direction = 1;
                } else {
                    nextDirection = 1;
                }

                break;
            case Qt::Key_Right:
                if (!moving) {
                    direction = 4;
                } else {
                    nextDirection = 4;
                }

                break;
            case Qt::Key_Down:
                if (!moving) {
                    direction = 3;
                } else {
                    nextDirection = 3;
                }


                break;
            case Qt::Key_Up:
                if (!moving) {
                    direction = 2;
                } else {
                    nextDirection = 2;
                }
                break;

            case Qt::Key_P:
                pause();
                break;

            case Qt::Key_Escape:
                this->close();

                break;
            default:
                break;
        }
    }

}

// This updates the pacman with the use of timer connection
void Pacmanwindow::updater() {
    static int scarestate = 0;
    static int counter = 0; // recognize when to update pacman
    counter++;

    // This will display the lives and level
    ui->livesLcdNumber_2->display(lives);
    checkLost();
    if(counter % (pacManTimeout/paintTimeout) == 0) {
        pacmanMove();
    }

    //ballPoints loop to check when pacman collides with balls
    for (int i = 0; i < ballPoints.size(); i++) {
        if (pacman->pacx == ballPoints[i].x() && pacman->pacy == ballPoints[i].y()) {
            ballPoints.remove(i);
            score++;
            ui->scoreLcdNumber_2->display(score);
        }
    }
    // Powerball points used to charge a power up for pacman
    for (int i = 0; i < PowerballPoints.size(); i++) {
        if (pacman->pacx == PowerballPoints[i].x() && pacman->pacy == PowerballPoints[i].y()) {
            PowerballPoints.remove(i);
            if (scared) { scarestate = 0; }
            scared = true;
            ghost[0]->isScared = true;
            ghost[1]->isScared = true;
            ghost[2]->isScared = true;
            ghost[3]->isScared = true;
        }
    }
    if(scared) {
        scarestate ++;
        if (scarestate == 1) { ghostsTimer->setInterval(ghostTimeOut*1.3); } // how fast they move when blue
        if (scarestate == 100) { // how long they stay blue for
            ghost[0]->whiteb = true;
            ghost[1]->whiteb = true;
            ghost[2]->whiteb = true;
            ghost[3]->whiteb = true;

        }
        if (scarestate == 150) {
            scared = false;
            scarestate = 0;
            ghostsTimer->setInterval(ghostTimeOut*1.1); // how fast they move when flashing white
            ghost[0]->whiteb = false;
            ghost[1]->whiteb = false;
            ghost[2]->whiteb = false;
            ghost[3]->whiteb = false;
            ghost[0]->isScared = false;
            ghost[1]->isScared = false;
            ghost[2]->isScared = false;
            ghost[3]->isScared = false;
        }
    }

    // This takes the time and divdes it by 30 to give the best representitive of seconds.
    ui->timeLcdNumber_2->display(counter / 8);
    

    ball->setpoints(ballPoints);
    powerball->setpoints(PowerballPoints);
    pacmanBoard->setballpoints(ballPoints);
    pacmanBoard->setpowerballpoints(PowerballPoints);
    pacmanBoard->fillpacpoints(pacX, pacY);

    // Animation
    ghost[0]->advance();
    ghost[1]->advance();
    ghost[2]->advance();
    ghost[3]->advance();
    pacman->advance();

    this->setFocus();
    scene->update(pacmanBoard->boundingRect());

}

// This pauses the timer.
void Pacmanwindow::pause() {
    //if you are not playing do nothing.
    if (!playing)
        return;

    isPaused = !isPaused;
    if (isPaused) {
        timer->stop();
        ghostsTimer->stop();

        text->paused = true;
        scene->addItem(text);
        text->setZValue(6); // sets priorty high so it will show over the graphicscene

    } else {
        scene->removeItem(text);
        timer->start();
        ghostsTimer->start();
    }

    update();
}

// This is an individual update for the ghosts, as they run on a seperate timer.
void Pacmanwindow::ghostUpdater()// updates the ghosts posistion
{
    for (int i = 0; i < 4; i++)
        if (ghostStart[i])
            ghostsMove(i);


    if (ghostX[3] == 450 / 2) { // if the ghost is in the rectangle keep adding
        state++;
    }
    if (!start) {
        for(int i = 0; i < 4; i++) {
            moveghostsInRect(i);
        }
    }

    // This tells the ghost to leave the rectangle when set false, because otherwise it won't know too
    QPoint p;
    for (int i = 0; i < 4; i++)
        if (!ghostStart[i]) {
            ghostY[i] -= 5;
            ghost[i]->setgosx(ghostX[i]);
            ghost[i]->setgosy(ghostY[i]);
            p.setX(ghostX[i]);
            p.setY(ghostY[i]);
            if (pacmanBoard->pacpoints.contains(p))
                ghostStart[i] = true;
        }
}

Pacmanwindow::~Pacmanwindow() {
    delete ui;
    delete scene;
    delete text;
    delete pacman;

    for (int i = 0; i < 4; ++i)
        delete ghost[i];

    delete pacmanBoard;
    delete ball;
    delete powerball;
    delete timer;
    delete ghostsTimer;
}
