#include "board.h"
#include "boardelements.h"
#include "server.h"
#include <QDebug>
#include "wall.h"
#include "gamestate.h"
#include "score.h"
#include "winnertext.h"

Board::Board(QGraphicsScene *scene)
{
    this->scene = scene;
}

void Board::drawInitialBoard(BoardElements *boardElements, IPlayerMoveHandler *playerMoveHandler, int playerNumber){
    this->playerNumber = playerNumber;

    drawInitialWallsAndScores(boardElements);
    drawInitialPlayers(playerMoveHandler);
    drawInitialGhosts();
    drawScoreBars();
}

void Board::drawInitialWallsAndScores(BoardElements *boardElements) {
    for (int x=0; x<BOARD_SIZE; x++) {
        for (int y=0; y<BOARD_SIZE ; y++) {
            ElementType elementType = boardElements->get(x,y);
            if(elementType == WALL) {
                putWallOnBoard(x, y);
            } else if(elementType == SCORE) {
                putScoreOnBoard(x, y);
            }
        }
    }
}

void Board::putWallOnBoard(int x, int y) {
    Wall *wall = new Wall();
    wall->setRect(x*WALL_SIZE,y*WALL_SIZE,WALL_SIZE,WALL_SIZE);

    QBrush brush;
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);

    wall->setBrush(brush);

    scene->addItem(wall);
}

void Board::drawInitialPlayers(IPlayerMoveHandler *playerMoveHandler)
{
    Player *player1 = new Player(playerMoveHandler);
    Player *player2 = new Player(playerMoveHandler);

    if(playerNumber == 0) {
        player1->setFlag(QGraphicsItem::ItemIsFocusable);
        player1->setFocus();
    } else if(playerNumber == 1) {
        player2->setFlag(QGraphicsItem::ItemIsFocusable);
        player2->setFocus();
    }

    player1->init();
    player2->init();

    QBrush brush1;
    brush1.setColor(Qt::yellow);
    brush1.setStyle(Qt::SolidPattern);

    QBrush brush2;
    brush2.setColor(Qt::green);
    brush2.setStyle(Qt::SolidPattern);

    player1->setBrush(brush1);
    player2->setBrush(brush2);

    scene->addItem(player1);
    scene->addItem(player2);

    players[0] = player1;
    players[1] = player2;
}

void Board::drawInitialGhosts()
{
    Ghost *ghost1 = new Ghost();
    Ghost *ghost2 = new Ghost();
    Ghost *ghost3 = new Ghost();

    ghost1->init();
    ghost2->init();
    ghost3->init();

    QBrush brush1;
    brush1.setColor(Qt::blue);
    brush1.setStyle(Qt::SolidPattern);

    QBrush brush2;
    brush2.setColor(Qt::blue);
    brush2.setStyle(Qt::SolidPattern);

    QBrush brush3;
    brush3.setColor(Qt::blue);
    brush3.setStyle(Qt::SolidPattern);

    ghost1->setBrush(brush1);
    ghost2->setBrush(brush2);
    ghost3->setBrush(brush3);

    scene->addItem(ghost1);
    scene->addItem(ghost2);
    scene->addItem(ghost3);

    ghosts[0] = ghost1;
    ghosts[1] = ghost2;
    ghosts[2] = ghost3;
}

void Board::putScoreOnBoard(int x, int y) {
    Score *score = new Score(x, y);

    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);

    score->setBrush(brush);

    scene->addItem(score);
    scores[scoresIndex] = score;
    scoresIndex++;
}

void Board::gameStateChanged(GameState *gameState) {
    static bool a = false;

    int player1XPosition = gameState->getPlayerX(0);
    int player1YPosition = gameState->getPlayerY(0);

    players[0]->setPosition(player1XPosition, player1YPosition);

    int player2XPosition = gameState->getPlayerX(1);
    int player2YPosition = gameState->getPlayerY(1);

    players[1]->setPosition(player2XPosition, player2YPosition);

    int ghost1XPosition = gameState->getGhostX(0);
    int ghost1YPosition = gameState->getGhostY(0);

    ghosts[0]->setPosition(ghost1XPosition, ghost1YPosition);

    int ghost2XPosition = gameState->getGhostX(1);
    int ghost2YPosition = gameState->getGhostY(1);

    ghosts[1]->setPosition(ghost2XPosition, ghost2YPosition);

    int ghost3XPosition = gameState->getGhostX(2);
    int ghost3YPosition = gameState->getGhostY(2);

    ghosts[2]->setPosition(ghost3XPosition, ghost3YPosition);

    int player1Score = gameState->getScore(0);
    int player2Score = gameState->getScore(1);

    scoreBars[0]->setScore(player1Score);
    scoreBars[1]->setScore(player2Score);

    checkWinner(gameState);

    removeScores(gameState);
}

Player **Board::getPlayers() {
    return players;
}

Ghost **Board::getGhosts() {
    return ghosts;
}

void Board::removeScores(GameState *gameState) {
    int player1XPosition = gameState->getPlayerX(0);
    int player1YPosition = gameState->getPlayerY(0);
    int player2XPosition = gameState->getPlayerX(1);
    int player2YPosition = gameState->getPlayerY(1);

    for (int i = 0; i < scoresIndex; i++) {
        if(scores[i] != NULL) {
            if((scores[i]->x == player1XPosition && scores[i]->y == player1YPosition) ||
                    (scores[i]->x == player2XPosition && scores[i]->y == player2YPosition)) {
                delete scores[i];
                scores[i] = NULL;
            }
        }
    }
}

void Board::drawScoreBars() {
    ScoreBar *player1ScoreBar = new ScoreBar();
    ScoreBar *player2ScoreBar = new ScoreBar();

    scene->addItem(player1ScoreBar);
    scene->addItem(player2ScoreBar);

    player1ScoreBar->setPos(0, -60);
    player2ScoreBar->setPos(0, -35);

    player1ScoreBar->setPlayer(0);
    player2ScoreBar->setPlayer(1);

    scoreBars[0] = player1ScoreBar;
    scoreBars[1] = player2ScoreBar;
}

void Board::checkWinner(GameState *gameState) {
    int winnerPlayer = gameState->getWinner();

    if(winnerPlayer > -1) {
        WinnerText *winner = new WinnerText();
        scene->addItem(winner);
        winner->setPos(150, -50);

        if(winnerPlayer == 0) {
            winner->setWinner(1);
        } else if(winnerPlayer == 1) {
            winner->setWinner(2);
        } else if(winnerPlayer == 2) {
            winner->setWinner(3);
        }
    }
}
