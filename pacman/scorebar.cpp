#include "scorebar.h"
#include <QFont>

ScoreBar::ScoreBar(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void ScoreBar::setPlayer(int playerIndex) {
    if(playerIndex == 0) {
        setDefaultTextColor(Qt::yellow);
    } else if(playerIndex == 1) {
        setDefaultTextColor(Qt::green);
    }
}

void ScoreBar::setScore(int score){
    this->score = score;
    setPlainText(QString("Score: ") + QString::number(score));
}

int ScoreBar::getScore(){
    return score;
}
