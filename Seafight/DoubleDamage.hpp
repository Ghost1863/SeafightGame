#ifndef DOUBLE_DAMAGE_HPP
#define DOUBLE_DAMAGE_HPP

#include "Ability.hpp"

class DoubleDamage : public Ability {
private:
	GameField& field;
	Coordinates coords;
public:
	DoubleDamage(GameField& field, Coordinates coords) :field(field), coords(coords) {};
	AbilityResult useAbility() override final;
};

#endif