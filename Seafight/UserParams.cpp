#include "UserParams.hpp"

UserParams::UserParams(GameField& field, ShipManager& sm,Coordinates& coords,int& currentDamage) :
	field(field), shipManager(sm),coords(coords),currentDamage(currentDamage) {};
