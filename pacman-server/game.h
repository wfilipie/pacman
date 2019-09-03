#ifndef GAME_H
#define GAME_H

#include "boardelements.h"
#include "gamestate.h"

class Game {
public:
    Game(BoardElements *board, GameState *gameState);
    void runOnce();
    void playerMoved(char playerMove, int playerIndex);
    GameState *gameState;
private:
    BoardElements *board;
    void moveGhost(int ghostIndex);
    bool isFieldFreeForGhost(ElementType elementType);
    bool isFieldFreeForPlayer(ElementType elementType);
    void checkGameOver();
    void gameOver();
};

#endif // GAME_H
