#ifndef DOUBLE_DAMAGE_HPP
#define DOUBLE_DAMAGE_HPP

#include "Ability.hpp"

class DoubleDamage : public Ability {
public:
	bool useAbility(GameField& field, Coordinates coords) override final;
};

#endif