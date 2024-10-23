#include "DoubleDamage.hpp"

bool DoubleDamage::useAbility(GameField& gf,Coordinates coords) {
	if (!gf.checkCurrentCoord(coords.x, coords.y)) {
		throw AttackOutOfBoundsException();
	}
	gf.attackCell(coords);
	if (gf.attackCell(coords)) {
		return true;
	}
	return false;
}

Abilities DoubleDamage::getAbilityType() {
	return Abilities::DoubleDamage;
}