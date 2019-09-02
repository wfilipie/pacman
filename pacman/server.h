#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
#include "boardelements.h"
#include "gamestate.h"

class Server {
public:
    Server(char address[], u_short port);
    ~Server();
    int receivePlayerNumber();
    void receiveInitialBoard(BoardElements *boardElements);
    void receiveGameState(GameState *gameState);
    void sendPlayerMove(char playerMove);
private:
    SOCKET serverHandler;
};

#endif // SERVER_H
