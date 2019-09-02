#include "game.h"
#include <QDebug>
#include "gamestate.h"

Game::Game(Server *server, Board *board) {
    this->server = server;
    this->board = board;
    gameState = new GameState();
}

void Game::init() {
    BoardElements *boardElements = new BoardElements();
    playerNumber = server->receivePlayerNumber();
    server->receiveInitialBoard(boardElements);
    board->drawInitialBoard(boardElements, this, playerNumber);

    server->receiveGameState(gameState);
    board->gameStateChanged(gameState);
}

void Game::runOnce() {
    server->sendPlayerMove(playerMove);
    server->receiveGameState(gameState);
    board->gameStateChanged(gameState);
}

void Game::handlePlayerMove(char playerMove) {
    this->playerMove = playerMove;
}
