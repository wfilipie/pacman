#include "game.h"
#include <stdlib.h>

Game::Game(BoardElements *board, GameState *gameState) {
    this->board = board;
    this->gameState = gameState;
}

void Game::runOnce() {
    moveGhost(0);
    moveGhost(1);
    moveGhost(2);
}

void Game::moveGhost(int ghostIndex) {
    int ghostX = gameState->getGhostX(ghostIndex);
    int ghostY = gameState->getGhostY(ghostIndex);

    ElementType elementAbove = board->get(ghostX, ghostY-1);
    ElementType elementBelow = board->get(ghostX, ghostY+1);
    ElementType elementRight = board->get(ghostX+1, ghostY);
    ElementType elementLeft = board->get(ghostX-1, ghostY);

    char possibleDirections[4];
    int possibleDirectionsIndex = 0;

    if(isFieldFreeForGhost(elementAbove)){
        possibleDirections[possibleDirectionsIndex] = 'u';
        possibleDirectionsIndex++;
    }
    if(isFieldFreeForGhost(elementBelow)){
        possibleDirections[possibleDirectionsIndex] = 'd';
        possibleDirectionsIndex++;
    }
    if(isFieldFreeForGhost(elementRight)){
        possibleDirections[possibleDirectionsIndex] = 'r';
        possibleDirectionsIndex++;
    }
    if(isFieldFreeForGhost(elementLeft)){
        possibleDirections[possibleDirectionsIndex] = 'l';
        possibleDirectionsIndex++;
    }

    // TODO implement random
    int randIndex = rand() % possibleDirectionsIndex;
    char randDirection = possibleDirections[randIndex];

    int newX = ghostX;
    int newY = ghostY;

    if(randDirection == 'u') {
        newY -= 1;
    } else if(randDirection == 'd') {
        newY += 1;
    } else if(randDirection == 'r') {
        newX += 1;
    } else if(randDirection == 'l') {
        newX -= 1;
    }

    gameState->setGhostPosition(newX, newY, ghostIndex);
    board->set(ghostX, ghostY, EMPTY);
    board->set(newX, newY, GHOST);
}

bool Game::isFieldFreeForGhost(ElementType elementType) {
    return (elementType != WALL && elementType != GHOST);
}
