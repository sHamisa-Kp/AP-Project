cmake_minimum_required(VERSION 3.10)
project(pacMan)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(pacMan
        ball.cpp
        ball.h
        ghost.cpp
        ghost.h
        main.cpp
        menu.cpp
        menu.h
        options.cpp
        options.h
        pacman.cpp
        pacman.h
        pacmanboard.cpp
        pacmanboard.h
        pacmanwindow.cpp
        pacmanwindow.h
        powerball.cpp
        powerball.h
        textdrawing.cpp
        textdrawing.h)
