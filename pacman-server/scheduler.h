#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QObject>
#include "game.h"
#include "client.h"

class Scheduler: public QObject {
    Q_OBJECT
public:
    Scheduler(Game *game, Client *client1, Client *client2);
public slots:
    void run();
private:
    Game *game;
    Client *client1;
    Client *client2;
};

#endif // SCHEDULER_H
