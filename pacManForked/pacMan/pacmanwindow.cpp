#include "pacmanwindow.h"
#include "ui_pacmanwindow.h"
#include <QThread>
#include <QtWidgets>
#include <iostream>
#include "options.h"

Pacmanwindow::Pacmanwindow(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Pacmanwindow) {


    // As windows needs this to be declared and start game, will contain different values as you can't set eveything to 0
    score = 0;
    level = 0;
    lives = 3; // needs to be set to a number because of lcd sometimes producing crazy numbers
    starting = 0;
    ghostX[0]= 450 / 2;
    ghostY[0]= 480 / 2;
    ghostX[1] = 450 / 2;
    ghostY[1] = 480 / 2;
    ghostX[2] = 450 / 2;
    ghostY[2] = 480 / 2;
    ghostX[3] = 450 / 2;
    ghostY[3] = 480 / 2;
    pacX = 410 / 2;
    pacY = 410;
    ghostMoving[0] = false;
    ghostMoving[1] = false;
    ghostMoving[2] = false;
    ghostMoving[3] = false;
    scared = false;
    start = false;
    direction = 0;
    moving = false;
    playing = false;
    isPaused = false;


    ///// Setting up the ui
    //Pacman(Qt::Dialog | Qt::FramelessWindowHint);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->scoreLabel->setText(name);// adds the name tp score label

    scene->setSceneRect(0, 0, 640, 480);
    ui->graphicsView->setSceneRect(scene->sceneRect());
    //Used to exit the application
//    connect(ui->exitButton, SIGNAL(clicked()), qApp, SLOT(closeAllWindows()));
//    ui->exitButton->setShortcut(QKeySequence("Escape"));


    text = new TextDrawing;
    text->over = false;
    text->paused = false;
    scene->addItem(text);
    text->setZValue(7);// This allows it to be ontop of the graphic screen
}

// A Method used to store the name and difficulty parsed from options
void Pacmanwindow::parseMessage(QString name, int temp) {
    this->name = name;
    ui->scoreLabel->setText("Score");
    difficulty = temp;
}

// A Method used to start the game both at the beginning, on new level and if there is a game over
void Pacmanwindow::startGame() {
    //std::cout << "******iAmStartGame********" << std::endl;
    level = 0;
    direction = 0;
    //start = false;
    playing = true;
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
    scene->removeItem(text); // remove the startup text ofc
    scene->addItem(pacmanBoard);
    scene->addItem(pacman);
    scene->addItem(ghost[0]);
    scene->addItem(ghost[1]);
    scene->addItem(ghost[2]);
    scene->addItem(ghost[3]);
    scene->addItem(text);

    //scene->removeItem(text);
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

    state = 0;

    waka->play(":/Sound/pacman_beginning.wav");
    //This is used to set the difficulty level as level will always be 0 at the beginning.
    if (starting == 0) // this may be a problem and if ghosts haven't
    {
        if (difficulty == 1) {
            easy();
            difficultyText = "easy";
        }
    }
}

// A method used to set the difficulty
void Pacmanwindow::easy() {
    // calling both timers to start the game
    timer = new QTimer(this);
    ghostsTimer = new QTimer(this);
    // Connecting the timers to the signal timeout which slows down the normal speed of timer and
    // setting each timer to there corresponding methods.
    connect(timer, SIGNAL(timeout()), this, SLOT(updater()));
    // Ghost needs a seperate timer as the ghosts will move a different speeds and need to
    // slow down regarding if they are in scared state or not
    connect(ghostsTimer, SIGNAL(timeout()), this, SLOT(ghostUpdater()));
    this->show();
    scene->update();
    this->update();

    lives = 3;
    timer->start();
    timer->start(100);
    ghostsTimer->start(120);
    // sets focus to everything on the screen
    this->setFocus();


}

// A method called when all lives are depleated resulting in changing the values.
void Pacmanwindow::endGame() {
    starting = 0;
    //Attempts at removing items but doesn't remove all of them
    scene->removeItem(pacman);
    scene->removeItem(ghost[0]);
    scene->removeItem(ghost[1]);
    scene->removeItem(ghost[2]);
    scene->removeItem(ghost[3]);
    scene->removeItem(pacmanBoard);
    //This displays the gameover text from the textdrawing class
    text->over = true;
    text->playing = false;
    start = false;
    playing = false;
    scene->update();
    timer->stop();
    ghostsTimer->stop();
    score = hiscore;
    score = 0;

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
    //if the direction you choose is not the same to the current dirrection switch through these
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
    switch (direction) {
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

    //Set the coordinates

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
        if (ghostDir[i] == 1 && ghostY[i]> pacY) {
            nextGhostDir[i] = 2;
        } else if (ghostDir[i] == 4 && ghostY[i]< pacY) {
            nextGhostDir[i] = 3;
        } else if (ghostDir[i] == 2 && ghostX[i]> pacX) {
            nextGhostDir[i] = 1;
        } else if (ghostDir[i] == 3 && ghostX[i]< pacX) {
            nextGhostDir[i] = 4;
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

    if (ghostX[i]<= 0) {
        ghostX[i]= 450;
        ghostY[i]= 230;
    } else if (ghostX[i]>= 450) {
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
        level += 1;
        starting += 1; // this means that difficulty won't be set again, so timer won't be increased.

        startGame();
    }

    // Checks for collisons between pacman and ghost
    for(int i = 0; i < 4; i++) {
        if (pacman->collidesWithItem(ghost[i])) {
            if(ghost[i]->is_Scared) {
//                std::cout << "I am scared" << std::endl;
                ghostX[i]= 450 / 2;
                ghost[i]->setgosx(ghostX[i]);
                ghostY[i]= 450 / 2;
                ghost[i]->setgosx(ghostX[i]);
                ghost[i]->is_Scared = false;
                ghost[i]->whiteb = false;
                ghostStart[i] = false;
                score += 100;
                waka->play(":/Sound/pacman_eatghost.wav");
            }
            else {
//                std::cout << "I am not scared" << std::endl;
                scared = false;
                ghost[0]->is_Scared = false;
                ghost[1]->is_Scared = false;
                ghost[2]->is_Scared = false;
                ghost[3]->is_Scared = false;
                ghost[0]->whiteb = false;
                ghost[1]->whiteb = false;
                ghost[2]->whiteb = false;
                ghost[3]->whiteb = false;
                // Sound for pacmans death
                if (lives > 0) {
                    waka->play(":/Sound/pacman_death.wav");
                    lives -= 1;
                    retry();
                } else {
                    // Adding the gameover scene text before endGame();
                    // because windows needs it to be declared first and makes for a smoother transistion
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

    // This error catching stops pacman from being moving until the ghosts can move.
    if (ghostX[3] == 450 / 2) { // if the ghost is in the rectangle keep adding
        state++;
        //    pacman->advance();
    }
    if (state == 1) { // when the state equals 2 release the ghosts(2 seconds as updater updates every 2 seconds)
        //        pacX=410/2;
        //        pacY=360;
        start = true;
        state = 0;
    }
    if (!start) {


    } else {

        // By adding values to direction or nextDirection it can work out which way pacman is going to move.
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

            case Qt::Key_A:
                if (!moving) {
                    direction = 1;
                } else {
                    nextDirection = 1;
                }

                break;
            case Qt::Key_D:

                if (!moving) {


                    direction = 4;

                } else {

                    nextDirection = 4;
                }

                break;
            case Qt::Key_S:
                if (!moving) {
                    direction = 3;
                } else {
                    nextDirection = 3;
                }


                break;
            case Qt::Key_W:
                if (!moving) {
                    direction = 2;
                } else {
                    nextDirection = 2;
                }
                break;

                break;

            case Qt::Key_P:
                pause();
                break;

            case Qt::Key_C:
                on_controlsButton_clicked();
                break;

            case Qt::Key_Escape:
                break;


            default:
                break;
        }
    }

}

// This updates the pacman with the use of timer connection
void Pacmanwindow::updater() {
    static int scarestate = 0;
    static int soundstate = 0;
    static int timeGame;
    // This will display the lives and level
    ui->livesLcdNumber_2->display(lives);
    checkLost();
    pacmanMove();

    //ballPoints loop to check when pacman collides with balls
    for (int i = 0; i < ballPoints.size(); i++) {
        if (pacman->pacx == ballPoints[i].x() && pacman->pacy == ballPoints[i].y()) {
            ballPoints.remove(i);
            score++;
            hiscore = score;
            text->score = score;
            // Setting the scores
            ui->highScroreLcdNumber_2->display(hiscore);
            ui->scoreLcdNumber_2->display(score);

            // This stops the sound play on a constant loop giving a break to
            // give a more realistic sounding through a loop created using the timer
            if (soundstate == 0) {
                waka->play(":/Sound/pacman_chomp.wav");
                soundstate++;
            } else {
                soundstate++;
                if (soundstate == 6) { soundstate = 0; }
            }


        }
    }
    // Powerball points used to charge a power up for pacman
    for (int i = 0; i < PowerballPoints.size(); i++) {
        if (pacman->pacx == PowerballPoints[i].x() && pacman->pacy == PowerballPoints[i].y()) {
            PowerballPoints.remove(i);
            if (scared) { scarestate = 0; }
            scared = true;
            ghost[0]->is_Scared = true;
            ghost[1]->is_Scared = true;
            ghost[2]->is_Scared = true;
            ghost[3]->is_Scared = true;
            waka->play(":/Sound/pacman_extrapac.wav");

        }
    }
    if (scared) {
        scarestate += 1;
        if (scarestate == 1) { ghostsTimer->setInterval(120); } // how fast they move when blue
        if (scarestate == 100) { // how long they stay blue for
            ghost[0]->whiteb = true;
            ghost[1]->whiteb = true;
            ghost[2]->whiteb = true;
            ghost[3]->whiteb = true;

        }
        if (scarestate == 150) {
            scared = false;
            scarestate = 0;
            ghostsTimer->setInterval(120); // how fast they move when flashing white
            ghost[0]->whiteb = false;
            ghost[1]->whiteb = false;
            ghost[2]->whiteb = false;
            ghost[3]->whiteb = false;
        }
    } else {
        ghost[0]->is_Scared = false;
        ghost[1]->is_Scared = false;
        ghost[2]->is_Scared = false;
        ghost[3]->is_Scared = false;
    }

    // This takes the time and divdes it by 30 to give the best representitive of seconds.
    if (timeGame > -1) {
        timeGame++;

        ui->timeLcdNumber_2->display(timeGame / 30);
    }

    text->timeElapsed = timeGame / 30;

    text->name = this->name;
    text->difficulty = difficultyText;

    ball->setpoints(ballPoints);
    powerball->setpoints(PowerballPoints);
    pacmanBoard->setballpoints(ballPoints);
    pacmanBoard->setpowerballpoints(PowerballPoints);
    pacmanBoard->fillpacpoints(pacX, pacY);
    //    pacman->advance();
    ghost[0]->advance();
    ghost[1]->advance();
    ghost[2]->advance();
    ghost[3]->advance();


    this->setFocus();
    scene->update(pacmanBoard->boundingRect());

    pacman->advance();
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
        // Add pause to the screen
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
    if (ghostStart[0] || ghostStart[1] || ghostStart[2] || ghostStart[3]) {
        if (ghostStart[0]) { ghostsMove(0); }
        if (ghostStart[1]) { ghostsMove(1); }
        if (ghostStart[2]) { ghostsMove(2); }
        if (ghostStart[3]) { ghostsMove(3); }
    }
    if (ghostX[3] == 450 / 2) { // if the ghost is in the rectangle keep adding
        state++;
    }
    if (state == 4 || 0) { // when the state equals 2 release the ghosts(2 seconds as updater updates every 2 seconds)
        start = true;

        state = 0;
    }
    if (!start) {
        for(int i = 0; i < 4; i++) {
            moveghostsInRect(i);
        }
    }

        // This tells the ghost to leave the rectangle when set false, because otherwise it won't know too
    else if (!ghostStart[3] || !ghostStart[2] || !ghostStart[1] || !ghostStart[0]) {
        QPoint p, p1, p2, p3;
        if (!ghostStart[3]) {
            ghostY[3] -= 5;
            ghost[3]->setgosx(ghostX[3]);
            ghost[3]->setgosy(ghostY[3]);
            p3.setX(ghostX[3]);
            p3.setY(ghostY[3]);
            if (pacmanBoard->pacpoints.contains(p3)) { ghostStart[3] = true; }
        }

        if (!ghostStart[2]) {
            ghostY[2] -= 5;
            ghost[2]->setgosx(ghostX[2]);
            ghost[2]->setgosy(ghostY[2]);
            p2.setX(ghostX[2]);
            p2.setY(ghostY[2]);
            if (pacmanBoard->pacpoints.contains(p2)) { ghostStart[2] = true; }
        }
        if (!ghostStart[1]) {
            ghostY[1] -= 5;
            ghost[1]->setgosx(ghostX[1]);
            ghost[1]->setgosy(ghostY[1]);
            p1.setX(ghostX[1]);
            p1.setY(ghostY[1]);
            if (pacmanBoard->pacpoints.contains(p1)) { ghostStart[1] = true; }
        }
        if (!ghostStart[0]) {
            ghostY[0]-= 5;
            ghost[0]->setgosx(ghostX[0]);
            ghost[0]->setgosy(ghostY[0]);
            p.setX(ghostX[0]);
            p.setY(ghostY[0]);
            if (pacmanBoard->pacpoints.contains(p)) { ghostStart[0] = true; }
        }

    }
}

Pacmanwindow::~Pacmanwindow() {
    delete ui;
}

// When pause button clicked pause the timer
void Pacmanwindow::on_pauseButton_clicked()// pauses the timer in the game
{
    pause();
}

// When controls buttons is clicked
void Pacmanwindow::on_controlsButton_clicked()// Change colour to black
{
    // make sure the game is paused.
    if (isPaused == false) {
        pause();
        // This opens a message box
        QPalette palette;
        palette.setColor(QPalette::Background, Qt::black);
        QMessageBox *controls = new QMessageBox;
        controls->setPalette(palette);
        controls->about(this,
                        tr("Controls"),
                        tr("<p align='center'><font><h1>Controls</h1>"
                           "<br>Press direction keys and aswd keys to move pacman across the screen.<br><br><br>"
                           "Press ESC to exit application.<br><br><br>Press P to pause the game</font></p>"));
    }
}

