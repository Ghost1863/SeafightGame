#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "UserParams.hpp"
#include "Randomizer.hpp"
#include "ConsoleDisplayer.hpp"
#include "InputHandler.hpp"


struct User {
	GameField field;
	ShipManager shipManager;
	AbilityManager abilityManager;
	Randomizer randomizer;
	User(GameField& field, AbilityManager& abilityManager,ShipManager& sm,int currentDamage);
	int currentDamage;
	User();
};

struct Bot {
	GameField field;
	ShipManager shipManager;
	Randomizer randomizer;
	Bot(GameField& field, ShipManager& sm);
	Bot();
};
#endif 
