#ifndef USER_PARAMS_HPP
#define USER_PARAMS_HPP
#include "GameField.hpp"
#include "ShipManager.hpp"

struct UserParams {
	GameField& field;
	ShipManager& shipManager;
	Coordinates& coords;
	int& currentDamage;
	UserParams(GameField& field, ShipManager& sm,Coordinates& coords,int& currentDamage);
};

#endif 