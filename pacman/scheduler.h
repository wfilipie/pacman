#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QObject>
#include "game.h"
#include "server.h"

class Scheduler: public QObject {
    Q_OBJECT
public:
    Scheduler(Game *game, Server *server);
public slots:
    void run();
private:
    Game *game;
    Server *server;
};

#endif // SCHEDULER_H
