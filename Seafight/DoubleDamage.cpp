#include "DoubleDamage.hpp"

void DoubleDamage::useAbility(GameField& gf,Coordinates coords) {
	gf.attackCell(coords);
	gf.attackCell(coords);
}

//Ability* DoubleDamage::createAbility(Abilities ability) {
//	return new DoubleDamage;
//}

Abilities DoubleDamage::getAbilityType() {
	return Abilities::DoubleDamage;
}