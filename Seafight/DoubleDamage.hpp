#ifndef DOUBLE_DAMAGE_HPP
#define DOUBLE_DAMAGE_HPP

#include "Ability.hpp"

class DoubleDamage : public Ability {
private:
	Coordinates coords;
public:
	bool useAbility(GameField& field, Coordinates coords) override final;
	virtual Abilities getAbilityType() override final;
};

#endif