#ifndef PLAYER_H
#define PLAYER_H

#include "client.h"
#include "figure.h"

class Player: private Figure {
public:
    Player(Client *client);
private:
    Client *client;
    int points;
};

#endif // PLAYER_H
