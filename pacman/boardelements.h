#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

#define BOARD_SIZE 15

#include "elementtype.h"

class BoardElements {
public:
    void set(int x, int y, ElementType elementType);
    ElementType get(int x, int y);
    char elements[BOARD_SIZE*BOARD_SIZE];
};

#endif // BOARDELEMENT_H
