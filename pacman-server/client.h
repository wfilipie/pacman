#ifndef CLIENT_H
#define CLIENT_H

#include <winsock2.h>
#include "boardelements.h"
#include "gamestate.h"

class Client {
public:
    Client(int port);
    ~Client();
    void sendBoard(BoardElements *boardElements);
    void sendGameState(GameState *gameState);
private:
    SOCKET clientHandler;
    char buffer[1024];
};

#endif // CLIENT_H
