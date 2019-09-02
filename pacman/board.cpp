#include "board.h"
#include "boardelements.h"
#include "server.h"
#include <QDebug>
#include "wall.h"
#include "gamestate.h"

#define WALL_SIZE 30


Board::Board(QGraphicsScene *scene)
{
    this->scene = scene;
}

void Board::drawInitialBoard(BoardElements *boardElements, IPlayerMoveHandler *playerMoveHandler, int playerNumber){
    this->playerNumber = playerNumber;

    for (int x=0; x<BOARD_SIZE; x++) {
        for (int y=0; y<BOARD_SIZE ; y++) {
            ElementType elementType = boardElements->get(x,y);
            if(elementType == WALL) {
                putWallOnBoard(x,y);
            }
        }
    }

    drawInitialPlayers(playerMoveHandler);
    drawInitialGhosts();
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

    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

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

void Board::gameStateChanged(GameState *gameState) {
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
}
