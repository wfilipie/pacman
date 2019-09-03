#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsRectItem>

class Score: public QGraphicsRectItem {
public:
    Score(int x, int y);
    int x;
    int y;
};

#endif // SCORE_H
