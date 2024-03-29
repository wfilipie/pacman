#include "gamestate.h"

GameState::GameState()
{
    setScore(0, 0);
    setScore(0, 1);
    state[12] = -1;
}

void GameState::setPlayerPosition(int x, int y, int playerIndex)
{
    state[playerIndex*2] = x;
    state[playerIndex*2 + 1] = y;
}

int GameState::getPlayerX(int playerIndex)
{
    return state[playerIndex*2];
}

int GameState::getPlayerY(int playerIndex)
{
    return state[playerIndex*2 + 1];
}

void GameState::setGhostPosition(int x, int y, int ghostIndex)
{
    state[ghostIndex*2 + 4] = x;
    state[ghostIndex*2 + 5] = y;
}

int GameState::getGhostX(int ghostIndex)
{
    return state[ghostIndex*2 + 4];
}

int GameState::getGhostY(int ghostIndex)
{
    return state[ghostIndex*2 + 5];
}

void GameState::setScore(int score, int playerIndex)
{
    state[playerIndex + 10] = score;
}

int GameState::getScore(int playerIndex)
{
    return state[playerIndex + 10];
}

void GameState::setWinner(int playerIndex)
{
    state[12] = playerIndex;
}

int GameState::getWinner()
{
    return state[12];
}

