#include <QApplication>
#include "pacmanwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    

    QString nametemp = "MeHdi";
    int difficulty{1};


    Pacmanwindow *w = new Pacmanwindow;
    w->parseMessage(nametemp, difficulty);
    w->show();

    return a.exec();
}
