#include <QApplication>
#include "pacmanwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Pacmanwindow *w = new Pacmanwindow;
    w->show();

    return a.exec();
}
