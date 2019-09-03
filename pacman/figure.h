#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsRectItem>

class Figure: public QGraphicsRectItem {

public:
    void init();
    void setPosition(int x, int y);
    int x;
    int y;
};

#endif // FIGURE_H
