#include "client.h"
#include <iostream>
#include <winsock2.h>
#include "boardelements.h"
#include <QDebug>

using namespace std;

Client::Client(int port) {
    WSADATA WSAData;

    SOCKET server;

    SOCKADDR_IN serverAddr, clientAddr;

    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(server, 0);

    cout << "Listening for incoming connections..." << endl;

    int clientAddrSize = sizeof(clientAddr);
    clientHandler = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize);
    if(clientHandler != INVALID_SOCKET)
    {
        cout << "Client connected!" << endl;
    } else {
        cout << "Error: " << clientHandler << endl;
    }
}

Client::~Client() {
    memset(buffer, 0, sizeof(buffer));

    closesocket(clientHandler);
    cout << "Client disconnected." << endl;
}

void Client::sendBoard(BoardElements *boardElements) {
    send(clientHandler, boardElements->elements, sizeof(boardElements->elements), 0);
}

void Client::sendGameState(GameState *gameState) {
    send(clientHandler, gameState->state, sizeof(gameState->state), 0);
}
