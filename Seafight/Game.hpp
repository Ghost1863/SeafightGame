#ifndef GAME_HPP
#define GAME_HPP

#include "GameField.hpp"
#include "ShipManager.hpp"
#include "ConsoleDisplayer.hpp"
#include "Randomizer.hpp"
#include "AbilityManager.hpp"
#include "InputHandler.hpp"
#include "Player.hpp"
#include "GameState.hpp"

class Game {
private:
    std::shared_ptr<User> user;
    std::shared_ptr<Bot> bot;
    GameState* state;
    bool isUserTurn;
    bool wasAbilityUsed;
    int currentRound;
public:
	Game();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

    void makeUserAbilityTurn();
    void makeUserAttackTurn();
    void makeUserTurn();
    void makeBotTurn();
    void makeTurn();

    void startNewRound();
    void startNewGame();

};

#endif