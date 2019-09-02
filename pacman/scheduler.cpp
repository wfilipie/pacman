#include "scheduler.h"
#include <QTimer>
#include <QDebug>

Scheduler::Scheduler(Game *game, Server *server) {
    this->game = game;
    this->server = server;

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(run()));

    timer->start(200);
}

void Scheduler::run() {
    game->runOnce();
}
