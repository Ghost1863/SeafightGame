#include "DoubleDamage.hpp"

DoubleDamage::DoubleDamage(GameField& field, Coordinates coords)
	:field(field), coords(coords) {};

AbilityResult DoubleDamage::useAbility() {
	if (!field.checkCurrentCoord(coords.x, coords.y)) {
		throw OutOfBoundsException();
	}
	field.attackCell(coords);
	if (field.attackCell(coords)) {
		return AbilityResult::ShipDestroyed;
	}
	return AbilityResult::ShipNotDestroyed;
}
