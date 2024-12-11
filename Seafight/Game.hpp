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
#include "GameLoader.hpp"
#include "GameSaver.hpp"
#include "UserParams.hpp"
#include "GameObserver.hpp"

class Game {
private:
    std::shared_ptr<int> currentRound;
    std::shared_ptr<User> user;
    std::shared_ptr<Bot> bot;
    GameState state;
    UserParams params;
    std::vector <GameObserver*> observers;
public:
	Game();
    void saveGame();
    void loadGame();

    void makeBotTurn();
    void makeUserAbilityTurn();
    void makeUserAttackTurn();

    void addObserver(GameObserver* observer);
    void startNewRound();
    void startNewGame();

    UserParams& getUserParams();
    GameState& getState();
};

#endif