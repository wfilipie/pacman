#ifndef SCOREBAR_H
#define SCOREBAR_H

#include <QGraphicsTextItem>

class ScoreBar: public QGraphicsTextItem{
public:
    ScoreBar(QGraphicsItem * parent=0);
    void setScore(int score);
    int getScore();
    void setPlayer(int playerIndex);
private:
    int score;
};

#endif // SCOREBAR_H
