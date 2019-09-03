#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
public:
    void setPlayerPosition(int x, int y, int playerIndex);
    int getPlayerX(int playerIndex);
    int getPlayerY(int playerIndex);

    void setGhostPosition(int x, int y, int ghostIndex);
    int getGhostX(int ghostIndex);
    int getGhostY(int ghostIndex);

    void setScore(int score, int playerIndex);
    int getScore(int playerIndex);

    void setWinner(int playerIndex);
    int getWinner();

    char state[13];
};

#endif // GAMESTATE_H
