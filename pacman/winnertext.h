#ifndef WINNERTEXT_H
#define WINNERTEXT_H

#include <QGraphicsTextItem>

class WinnerText: public QGraphicsTextItem{
public:
    WinnerText(QGraphicsItem * parent=0);
    void setWinner(int playerNumber);
};

#endif // WINNERTEXT_H
