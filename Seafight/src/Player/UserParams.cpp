#include "UserParams.hpp"

UserParams::UserParams(GameField& field, ShipManager& sm) :
	field(field), shipManager(sm),coords(Coordinates{-1,-1}), currentDamage(1) {};
