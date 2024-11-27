#include "DoubleDamage.hpp"

DoubleDamage::DoubleDamage(int& currentDamage)
	:currentDamage(currentDamage),isCoordsRequired(false) {};


AbilityResult DoubleDamage::useAbility() {
	currentDamage++;
	return AbilityResult::ShipNotDestroyed;
}
