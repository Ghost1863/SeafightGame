#ifndef GAME_OUTPUT_CONTROLLER
#define GAME_OUTPUT_CONTROLLER
#include "Game.hpp"
#include "GameObserver.hpp"

template <class Output>

class GameOutputController : public GameObserver
{
private:
	GameState& state;	
	Output& output;

public:
	GameOutputController(GameState& state, Output& output) : state(state), output(output)  {};

	void userAttackTurnEnd() override {
		output.displayString("Your turn:");
		output.displayTwoFields(state.getUser()->field, state.getBot()->field);
		output.displayAbilities(state.getUser()->abilityManager);
	}

	void userAbilityTurnEnd(std::string result) override {
		output.displayString("Your turn:");
		output.displayTwoFields(state.getUser()->field, state.getBot()->field);
		output.displayAbilities(state.getUser()->abilityManager);
		output.displayString(result);
	}

	void botTurnEnd()override {
		output.displayString("Bot turn:");
		output.displayTwoFields(state.getUser()->field, state.getBot()->field);
		output.displayAbilities(state.getUser()->abilityManager);
	}

	void botWin() override {
		output.displayGameOverMessage();
		output.displayString("Starting new game");
	}
	void userWin() override{
		output.displayVictoryMessage(state.getCurrentRound());
	}
	
	void gameLoadSuccess() override {
		output.displayColoredString("Game successfully loaded", 32);
		output.displayTwoFields(state.getUser()->field, state.getBot()->field);
		output.displayAbilities(state.getUser()->abilityManager);
	}
};

#endif
