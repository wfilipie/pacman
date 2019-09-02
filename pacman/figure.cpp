#include "figure.h"
#include <QDebug>

#define FIGURE_SIZE 30

void Figure::init() {
    setRect(0, 0, FIGURE_SIZE, FIGURE_SIZE);
}

void Figure::setPosition(int x, int y) {
    setPos(x*FIGURE_SIZE, y*FIGURE_SIZE);
}
