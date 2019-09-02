#ifndef GAME_H
#define GAME_H

#include "boardelements.h"
#include "gamestate.h"

class Game {
public:
    Game(BoardElements *board, GameState *gameState);
    void runOnce();
    GameState *gameState;
private:
    BoardElements *board;
    void moveGhost(int ghostIndex);
    bool isFieldFreeForGhost(ElementType elementType);
};

#endif // GAME_H
