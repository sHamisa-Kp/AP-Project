#-------------------------------------------------
#
# Project created by QtCreator 2018-07-13T20:14:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pacManFromMehdi
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

SOURCES += \
    main.cpp \
    ball.cpp \
    ghost.cpp \
    menu.cpp \
    options.cpp \
    pacman.cpp \
    pacmanboard.cpp \
    pacmanwindow.cpp \
    powerball.cpp \
    textdrawing.cpp

HEADERS += \
    ball.h \
    ghost.h \
    menu.h \
    options.h \
    pacman.h \
    pacmanboard.h \
    pacmanwindow.h \
    powerball.h \
    textdrawing.h

FORMS += \
    menu.ui \
    options.ui \
    pacmanwindow.ui

RESOURCES += \
    Resources.qrc \
    Images.qrc \
    Sounds.qrc