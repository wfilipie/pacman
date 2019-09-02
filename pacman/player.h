#ifndef PLAYER_H
#define PLAYER_H

#include "figure.h"
#include "iplayermovehandler.h"

class Player: public Figure {
public:
    Player(IPlayerMoveHandler *playerMoveHandler);
    void keyPressEvent(QKeyEvent * event);
private:
    IPlayerMoveHandler *playerMoveHandler;
    int points;
};

#endif // PLAYER_H
