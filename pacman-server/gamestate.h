#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
public:
    GameState();

    void setPlayerPosition(int x, int y, int playerIndex);
    int getPlayerX(int playerIndex);
    int getPlayerY(int playerIndex);

    void setGhostPosition(int x, int y, int ghostIndex);
    int getGhostX(int ghostIndex);
    int getGhostY(int ghostIndex);

    void setScore(int score, int playerIndex);
    int getScore(int playerIndex);

    char state[12];
};

#endif // GAMESTATE_H
