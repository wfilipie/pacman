#include "scheduler.h"
#include <QTimer>
#include <QDebug>

Scheduler::Scheduler(Game *game, Client *client1, Client *client2) {
    this->game = game;
    this->client1 = client1;
    this->client2 = client2;

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(run()));

    timer->start(200);
}

void Scheduler::run() {
    game->runOnce();
    char player1Move = client1->recievePlayerMove();
    game->playerMoved(player1Move, 0);
    client1->sendGameState(game->gameState);
}
