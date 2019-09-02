#ifndef BOARD_H
#define BOARD_H

#include "boardelements.h"
#include "player.h"
#include "ghost.h"

class Board {
public:
    void gameStateChanged(BoardElements *boardElements);
private:
    Player players[2];
    Ghost ghosts[3];
    BoardElements *boardElements;
};

#endif // BOARD_H
