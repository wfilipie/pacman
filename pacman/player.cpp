#include "player.h"
#include <QKeyEvent>

Player::Player(IPlayerMoveHandler *playerMoveHandler) {
    this->playerMoveHandler = playerMoveHandler;
}

void Player::keyPressEvent(QKeyEvent *event) {

    char move;

    if(event->key() == Qt::Key_Up) {
        move = 'u';
    } else if(event->key() == Qt::Key_Down) {
        move = 'd';
    } else if(event->key() == Qt::Key_Right) {
        move = 'r';
    } else if(event->key() == Qt::Key_Left) {
        move = 'l';
    }

    this->playerMoveHandler->handlePlayerMove(move);
}
