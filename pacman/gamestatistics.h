#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include <QDebug>

template <class T>
class GameStatistics {
public:
    GameStatistics (T *figure) {
        this->figure = figure;
    }
    void print() {
        qDebug() << "Current position: [" << figure->x << ", " << figure->y << "]";
    }
private:
    T *figure;
};


#endif // GAMESTATISTICS_H
