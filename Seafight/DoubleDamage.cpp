#include "DoubleDamage.hpp"

bool DoubleDamage::useAbility(GameField& gf,Coordinates coords) {
	if (!gf.checkCurrentCoord(coords.x, coords.y)) {
		throw OutOfBoundsException();
	}
	gf.attackCell(coords);
	if (gf.attackCell(coords)) {
		return true;
	}
	return false;
}
