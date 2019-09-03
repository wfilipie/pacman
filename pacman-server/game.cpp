#include "game.h"
#include <stdlib.h>
#include <QDebug>

Game::Game(BoardElements *board, GameState *gameState) {
    this->board = board;
    this->gameState = gameState;
}

void Game::runOnce() {
    moveGhost(0);
    moveGhost(1);
    moveGhost(2);
}

void Game::playerMoved(char playerMove, int playerIndex) {

    int playerX = gameState->getPlayerX(playerIndex);
    int playerY = gameState->getPlayerY(playerIndex);

    ElementType elementAbove = board->get(playerX, playerY-1);
    ElementType elementBelow = board->get(playerX, playerY+1);
    ElementType elementRight = board->get(playerX+1, playerY);
    ElementType elementLeft = board->get(playerX-1, playerY);

    int newX = playerX;
    int newY = playerY;

    if(isFieldFreeForPlayer(elementAbove) && playerMove == 'u'){
        newY -= 1;
    }
    if(isFieldFreeForPlayer(elementBelow) && playerMove == 'd'){
        newY += 1;
    }
    if(isFieldFreeForPlayer(elementRight) && playerMove == 'r'){
        newX += 1;
    }
    if(isFieldFreeForPlayer(elementLeft) && playerMove == 'l'){
        newX -= 1;
    }

    if(board->get(newX, newY) == SCORE) {
        board->set(newX, newY, EMPTY);
        int score = gameState->getScore(playerIndex);
        gameState->setScore(score + 1, playerIndex);
    }

    gameState->setPlayerPosition(newX, newY, playerIndex);
    board->set(playerX, playerY, EMPTY);
    board->set(newX, newY, PLAYER);
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

bool Game::isFieldFreeForPlayer(ElementType elementType) {
    return (elementType != WALL && elementType != PLAYER);
}
