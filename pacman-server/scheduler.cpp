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
    client1->sendGameState(game->gameState);
}
