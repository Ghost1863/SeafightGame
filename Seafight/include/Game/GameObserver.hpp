#ifndef GAMEOBSERVER_HPP  
#define GAMEOBSERVER_HPP

#include "Game.hpp"

class GameObserver {
public:

    virtual void userAttackTurnEnd() = 0;
    virtual void userAbilityTurnEnd(std::string result) = 0;
    virtual void botTurnEnd() = 0;
    virtual void botWin() = 0;
    virtual void userWin() = 0;
    virtual void gameLoadSuccess() = 0;
    virtual ~GameObserver() {}
};

#endif 