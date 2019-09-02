#ifndef BOARDBUILDER_H
#define BOARDBUILDER_H

#include "boardelements.h"
#include "gamestate.h"

void buildBoard(BoardElements *boardElements);
void buildGameState(GameState *gameState, BoardElements *boardElements);

#endif // BOARDBUILDER_H
