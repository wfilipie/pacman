#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "console.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include "server.h"
#include "board.h"
#include "game.h"
#include "scheduler.h"
#include <winsock2.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    char address[] = "127.0.0.1";
    u_short port = 11111;
    Server *server = new Server(address, port);

    QGraphicsScene *scene = new QGraphicsScene();

    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    view->setFixedSize(600, 600);
    scene->setSceneRect(0, -5, 500, 500);

    Board *board = new Board(scene);
    Game *game = new Game(server, board);
    game->init();
    game->runOnce();

    Scheduler *scheduler = new Scheduler(game, server);

    return a.exec();
}
