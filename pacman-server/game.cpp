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

    checkGameOver();
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

void Game::checkGameOver() {
    int player1X = gameState->getPlayerX(0);
    int player1Y = gameState->getPlayerY(0);
    int player2X = gameState->getPlayerX(1);
    int player2Y = gameState->getPlayerY(1);

    int ghost1X = gameState->getGhostX(0);
    int ghost1Y = gameState->getGhostY(0);
    int ghost2X = gameState->getGhostX(1);
    int ghost2Y = gameState->getGhostY(1);
    int ghost3X = gameState->getGhostX(2);
    int ghost3Y = gameState->getGhostY(2);

    if((player1X == ghost1X && player1Y == ghost1Y) ||
            (player1X == ghost2X && player1Y == ghost2Y) ||
            (player1X == ghost3X && player1Y == ghost3Y)) {
        gameOver();
    } else if((player2X == ghost1X && player2Y == ghost1Y) ||
            (player2X == ghost2X && player2Y == ghost2Y) ||
            (player2X == ghost3X && player2Y == ghost3Y)) {
        gameOver();
    }
}

void Game::gameOver() {
    int winner;

    int score1 = gameState->getScore(0);
    int score2 = gameState->getScore(1);

    if(score1 > score2) {
        winner = 0;
    } else if(score1 < score2) {
        winner = 1;
    } else {
        winner = 2;
    }

    gameState->setWinner(winner);
}
