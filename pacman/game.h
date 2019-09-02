#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "server.h"

class Game {
public:
    Game(Server *server, Board *board);
    void init();
    void runOnce();
private:
    Server *server;
    Board *board;
    GameState *gameState;
};

#endif // GAME_H
