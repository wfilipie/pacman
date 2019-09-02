#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "server.h"
#include "iplayermovehandler.h"

class Game: public IPlayerMoveHandler {
public:
    Game(Server *server, Board *board);
    void init();
    void runOnce();
    virtual void handlePlayerMove(char playerMove);
private:
    Server *server;
    Board *board;
    GameState *gameState;
    char playerMove;
    int playerNumber;
};

#endif // GAME_H
