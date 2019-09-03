#-------------------------------------------------
#
# Project created by QtCreator 2019-08-31T12:32:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pacman
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

CONFIG += c++11

SOURCES += \
        main.cpp \
    console.cpp \
    server.cpp \
    player.cpp \
    figure.cpp \
    board.cpp \
    ghost.cpp \
    game.cpp \
    boardelements.cpp \
    wall.cpp \
    gamestate.cpp \
    scheduler.cpp \
    score.cpp

HEADERS += \
    console.h \
    server.h \
    player.h \
    figure.h \
    board.h \
    ghost.h \
    game.h \
    elementtype.h \
    boardelements.h \
    wall.h \
    gamestate.h \
    scheduler.h \
    iplayermovehandler.h \
    score.h

LIBS += C:\Qt\Tools\mingw730_64\x86_64-w64-mingw32\lib\libws2_32.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
