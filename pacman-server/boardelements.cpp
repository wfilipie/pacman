#include "boardelements.h"

void BoardElements::set(int x, int y, ElementType elementType) {
    elements[x * BOARD_SIZE + y] = elementType;
}

ElementType BoardElements::get(int x, int y) {
    char element = elements[x * BOARD_SIZE + y];
    return (ElementType) element;
}
