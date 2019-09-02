#include "boardelements.h"
#include "elementtype.h"
#include "boardbuilder.h"

void buildBoard(BoardElements *boardElements) {
    // upper border
    boardElements->set(0, 0, WALL);
    boardElements->set(1, 0, WALL);
    boardElements->set(2, 0, WALL);
    boardElements->set(3, 0, WALL);
    boardElements->set(4, 0, WALL);
    boardElements->set(5, 0, WALL);
    boardElements->set(6, 0, WALL);
    boardElements->set(7, 0, WALL);
    boardElements->set(8, 0, WALL);
    boardElements->set(9, 0, WALL);
    boardElements->set(10, 0, WALL);
    boardElements->set(11, 0, WALL);
    boardElements->set(12, 0, WALL);
    boardElements->set(13, 0, WALL);
    boardElements->set(14, 0, WALL);

    // lower border
    boardElements->set(0, 14, WALL);
    boardElements->set(1, 14, WALL);
    boardElements->set(2, 14, WALL);
    boardElements->set(3, 14, WALL);
    boardElements->set(4, 14, WALL);
    boardElements->set(5, 14, WALL);
    boardElements->set(6, 14, WALL);
    boardElements->set(7, 14, WALL);
    boardElements->set(8, 14, WALL);
    boardElements->set(9, 14, WALL);
    boardElements->set(10, 14, WALL);
    boardElements->set(11, 14, WALL);
    boardElements->set(12, 14, WALL);
    boardElements->set(13, 14, WALL);
    boardElements->set(14, 14, WALL);

    // left border
    boardElements->set(0, 0, WALL);
    boardElements->set(0, 1, WALL);
    boardElements->set(0, 2, WALL);
    boardElements->set(0, 3, WALL);
    boardElements->set(0, 4, WALL);
    boardElements->set(0, 5, WALL);
    boardElements->set(0, 6, WALL);
    boardElements->set(0, 7, WALL);
    boardElements->set(0, 8, WALL);
    boardElements->set(0, 9, WALL);
    boardElements->set(0, 10, WALL);
    boardElements->set(0, 11, WALL);
    boardElements->set(0, 12, WALL);
    boardElements->set(0, 13, WALL);
    boardElements->set(0, 14, WALL);

    // right border
    boardElements->set(14, 0, WALL);
    boardElements->set(14, 1, WALL);
    boardElements->set(14, 2, WALL);
    boardElements->set(14, 3, WALL);
    boardElements->set(14, 4, WALL);
    boardElements->set(14, 5, WALL);
    boardElements->set(14, 6, WALL);
    boardElements->set(14, 7, WALL);
    boardElements->set(14, 8, WALL);
    boardElements->set(14, 9, WALL);
    boardElements->set(14, 10, WALL);
    boardElements->set(14, 11, WALL);
    boardElements->set(14, 12, WALL);
    boardElements->set(14, 13, WALL);
    boardElements->set(14, 14, WALL);

    // inner walls
    boardElements->set(1, 4, WALL);
    boardElements->set(1, 6, WALL);

    boardElements->set(2, 2, WALL);
    boardElements->set(2, 4, WALL);
    boardElements->set(2, 8, WALL);
    boardElements->set(2, 9, WALL);
    boardElements->set(2, 10, WALL);
    boardElements->set(2, 12, WALL);
    boardElements->set(2, 13, WALL);

    boardElements->set(3, 4, WALL);
    boardElements->set(3, 5, WALL);
    boardElements->set(3, 6, WALL);
    boardElements->set(3, 8, WALL);
    boardElements->set(3, 13, WALL);

    boardElements->set(4, 2, WALL);
    boardElements->set(4, 8, WALL);
    boardElements->set(4, 9, WALL);
    boardElements->set(4, 11, WALL);
    boardElements->set(4, 13, WALL);

    boardElements->set(5, 2, WALL);
    boardElements->set(5, 4, WALL);
    boardElements->set(5, 6, WALL);
    boardElements->set(5, 8, WALL);
    boardElements->set(5, 9, WALL);
    boardElements->set(5, 11, WALL);
    boardElements->set(5, 13, WALL);

    boardElements->set(6, 4, WALL);
    boardElements->set(6, 11, WALL);

    boardElements->set(7, 1, WALL);
    boardElements->set(7, 2, WALL);
    boardElements->set(7, 4, WALL);
    boardElements->set(7, 5, WALL);
    boardElements->set(7, 6, WALL);
    boardElements->set(7, 7, WALL);
    boardElements->set(7, 8, WALL);
    boardElements->set(7, 9, WALL);
    boardElements->set(7, 11, WALL);
    boardElements->set(7, 12, WALL);

    boardElements->set(8, 4, WALL);
    boardElements->set(8, 11, WALL);

    boardElements->set(9, 2, WALL);
    boardElements->set(9, 4, WALL);
    boardElements->set(9, 6, WALL);
    boardElements->set(9, 8, WALL);
    boardElements->set(9, 9, WALL);
    boardElements->set(9, 11, WALL);
    boardElements->set(9, 13, WALL);

    boardElements->set(10, 2, WALL);
    boardElements->set(10, 8, WALL);
    boardElements->set(10, 9, WALL);
    boardElements->set(10, 11, WALL);
    boardElements->set(10, 13, WALL);

    boardElements->set(11, 4, WALL);
    boardElements->set(11, 5, WALL);
    boardElements->set(11, 6, WALL);
    boardElements->set(11, 8, WALL);
    boardElements->set(11, 13, WALL);

    boardElements->set(12, 2, WALL);
    boardElements->set(12, 4, WALL);
    boardElements->set(12, 8, WALL);
    boardElements->set(12, 9, WALL);
    boardElements->set(12, 10, WALL);
    boardElements->set(12, 12, WALL);
    boardElements->set(12, 13, WALL);

    boardElements->set(13, 4, WALL);
    boardElements->set(13, 6, WALL);
}

void buildGameState(GameState *gameState, BoardElements *boardElements) {
    gameState->setPlayerPosition(1,1,0);
    gameState->setPlayerPosition(13,13,1);

    gameState->setGhostPosition(6, 10, 0);
    gameState->setGhostPosition(7, 10, 1);
    gameState->setGhostPosition(8, 10, 2);

    boardElements->set(1, 1, PLAYER);
    boardElements->set(13, 13, PLAYER);

    boardElements->set(6, 10, GHOST);
    boardElements->set(7, 10, GHOST);
    boardElements->set(8, 10, GHOST);
}
