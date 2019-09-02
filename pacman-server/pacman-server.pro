#-------------------------------------------------
#
# Project created by QtCreator 2019-08-31T21:39:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pacman-server
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
    client.cpp \
    player.cpp \
    ghost.cpp \
    figure.cpp \
    boardelements.cpp \
    boardbuilder.cpp \
    gamestate.cpp \
    game.cpp \
    scheduler.cpp

HEADERS += \
    client.h \
    figure.h \
    player.h \
    ghost.h \
    boardelements.h \
    elementtype.h \
    boardbuilder.h \
    gamestate.h \
    game.h \
    scheduler.h

FORMS +=

LIBS += C:\Qt\Tools\mingw730_64\x86_64-w64-mingw32\lib\libws2_32.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
