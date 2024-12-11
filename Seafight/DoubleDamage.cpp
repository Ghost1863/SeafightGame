#include "DoubleDamage.hpp"

DoubleDamage::DoubleDamage(int& currentDamage)
	:currentDamage(currentDamage),isCoordsRequired(false) {};


std::unique_ptr<AbilityResult> DoubleDamage::useAbility() {
	currentDamage++;
	return std::make_unique<DamageIncreasedResult>();
}
