#include "score.h"
#include "wall.h"

#define SCORE_SIZE 5

Score::Score(int x, int y) {
    this->x = x;
    this->y = y;

    int sceneX = x * WALL_SIZE + WALL_SIZE / 2 - 2;
    int sceneY = y * WALL_SIZE + WALL_SIZE / 2 - 2;
    setRect(sceneX,sceneY,SCORE_SIZE,SCORE_SIZE);
}
