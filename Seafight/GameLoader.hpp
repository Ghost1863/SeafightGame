#ifndef GAME_LOADER_HPP
#define GAME_LOADER_HPP
#include "GameState.hpp"

class GameLoader {

private:
	GameState& state;

public:
	GameLoader(GameState& state) : state(state) {};
	void load();
	void placeShipsBack(ShipManager& shipManager, GameField& field);
};
#endif