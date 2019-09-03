#include "winnertext.h"
#include <QFont>

WinnerText::WinnerText(QGraphicsItem *parent): QGraphicsTextItem(parent){
    setPlainText(QString("Winner is player number: "));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void WinnerText::setWinner(int playerNumber) {
    if(playerNumber == 3) {
        setPlainText(QString("Draw! No winner."));
    } else {
        setPlainText(QString("Winner is player number: ") + QString::number(playerNumber));
    }
}


