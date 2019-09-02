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
    server->receiveInitialBoard(boardElements);
    board->drawInitialBoard(boardElements);
}

void Game::runOnce() {
    server->receiveGameState(gameState);
    board->gameStateChanged(gameState);
}
