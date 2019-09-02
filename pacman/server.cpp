#include "server.h"
#include <iostream>
#include <winsock2.h>
#include "boardelements.h"
#include <QDebug>

using namespace std;

Server::Server(char address[], u_short port) {

    WSADATA WSAData;
    SOCKADDR_IN addr;

    WSAStartup(MAKEWORD(2,0), &WSAData);
    serverHandler = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr(address);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    connect(serverHandler, (SOCKADDR *)&addr, sizeof(addr));
    cout << "Connected to server!" << endl;
}

Server::~Server() {
    closesocket(serverHandler);
    WSACleanup();

    cout << "Socket closed." << endl << endl;
}

void Server::receiveInitialBoard(BoardElements *boardElements) {
    recv(serverHandler, boardElements->elements, sizeof(boardElements->elements), 0);
}

void Server::receiveGameState(GameState *gameState)
{
    recv(serverHandler, gameState->state, sizeof(gameState->state), 0);
}
