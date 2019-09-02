#ifndef BOARD_H
#define BOARD_H

#include "boardelements.h"
#include "player.h"
#include "ghost.h"
#include "server.h"
#include "gamestate.h"
#include "iplayermovehandler.h"
#include <QGraphicsScene>

class Board {
public:
    Board(QGraphicsScene *scene);
    void drawInitialBoard(BoardElements *boardElements, IPlayerMoveHandler *playerMoveHandler, int playerNumber);
    void gameStateChanged(GameState *gameState);
private:
    BoardElements *boardElements;
    Player *players[2];
    Ghost *ghosts[3];
    QGraphicsScene *scene;
    int playerNumber;
    void putWallOnBoard(int x, int y);
    void drawInitialPlayers(IPlayerMoveHandler *playerMoveHandler);
    void drawInitialGhosts();
};

#endif // BOARD_H
