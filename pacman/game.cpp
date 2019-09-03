#include "game.h"
#include <QDebug>
#include "gamestate.h"
#include "gamestatistics.h"

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

    printStatistics();
}

void Game::runOnce() {
    server->sendPlayerMove(playerMove);
    server->receiveGameState(gameState);
    board->gameStateChanged(gameState);
}

void Game::handlePlayerMove(char playerMove) {
    this->playerMove = playerMove;
}

void Game::printStatistics() {
    Player **players = board->getPlayers();
    Ghost **ghosts = board->getGhosts();

    GameStatistics<Player> *stats1 = new GameStatistics<Player>(players[0]);
    GameStatistics<Player> *stats2 = new GameStatistics<Player>(players[1]);
    GameStatistics<Ghost> *stats3 = new GameStatistics<Ghost>(ghosts[0]);
    GameStatistics<Ghost> *stats4 = new GameStatistics<Ghost>(ghosts[1]);
    GameStatistics<Ghost> *stats5 = new GameStatistics<Ghost>(ghosts[2]);

    stats1->print();
    stats2->print();
    stats3->print();
    stats4->print();
    stats5->print();

    delete stats1;
    delete stats2;
    delete stats3;
    delete stats4;
    delete stats5;
}
