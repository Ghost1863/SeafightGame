#ifndef GAME_SAVER_HPP
#define GAME_SAVER_HPP
#include "GameState.hpp"

class GameSaver {

private:
	GameState& state;

public:
	GameSaver(GameState& state) :state(state) {};
	void save();
};

#endif 
