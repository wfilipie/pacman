#ifndef IKEYPRESSHANDLER_H
#define IKEYPRESSHANDLER_H

class IPlayerMoveHandler {
public:
    virtual ~IPlayerMoveHandler() {}
    virtual void handlePlayerMove(char playerMove) = 0;
};

#endif // IKEYPRESSHANDLER_H
