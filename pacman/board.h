#ifndef BOARD_H
#define BOARD_H

#include "boardelements.h"
#include "player.h"
#include "ghost.h"
#include "server.h"
#include "gamestate.h"
#include "iplayermovehandler.h"
#include "score.h"
#include "scorebar.h"
#include <QGraphicsScene>

class Board {
public:
    Board(QGraphicsScene *scene);
    void drawInitialBoard(BoardElements *boardElements, IPlayerMoveHandler *playerMoveHandler, int playerNumber);
    void gameStateChanged(GameState *gameState);
private:
    BoardElements *boardElements;
    Player *players[2];
    Ghost *ghosts[3];
    Score *scores[100];
    ScoreBar *scoreBars[2];
    int scoresIndex = 0;
    QGraphicsScene *scene;
    int playerNumber;
    void drawInitialWallsAndScores(BoardElements *boardElements);
    void putWallOnBoard(int x, int y);
    void drawInitialPlayers(IPlayerMoveHandler *playerMoveHandler);
    void drawInitialGhosts();
    void putScoreOnBoard(int x, int y);
    void removeScores(GameState *gameState);
    void drawScoreBars();
    void checkWinner(GameState *gameState);
};

#endif // BOARD_H
