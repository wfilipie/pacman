#include <iostream>
#include <winsock2.h>
#include "client.h"
#include "boardelements.h"
#include "board.h"
#include "boardbuilder.h"
#include "gamestate.h"
#include "game.h"
#include "scheduler.h"
#include <QDebug>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    cout << "Started server!" << endl;

    cout << "Connecting to 1st client" << endl;
    Client *client1 = new Client(11111);

    //    cout << "Connecting to 2nd client" << endl;
    //    Client *client2 = new Client(11112);

    BoardElements *boardElements = new BoardElements();
    buildBoard(boardElements);

    GameState *gameState = new GameState();
    buildGameState(gameState, boardElements);

    client1->sendPlayerNumber(0);
    client1->sendBoard(boardElements);
    client1->sendGameState(gameState);

    Game *game = new Game(boardElements, gameState);

    Scheduler *scheduler = new Scheduler(game, client1, client1);
    scheduler->run();

    return a.exec();
}
