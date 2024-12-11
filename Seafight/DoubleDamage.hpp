#ifndef DOUBLE_DAMAGE_HPP
#define DOUBLE_DAMAGE_HPP

#include "Ability.hpp"

class DoubleDamage : public Ability {
private:
	int& currentDamage;
	bool isCoordsRequired;
public:
	DoubleDamage(int& currentDamage);
	std::unique_ptr<AbilityResult> useAbility() override final;
};

#endif