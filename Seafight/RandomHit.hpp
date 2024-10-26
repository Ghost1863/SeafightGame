#ifndef RANDOM_HIT_HPP
#define RANDOM_HIT_HPP

#include "Ability.hpp"

class RandomHit :public Ability {
public:
	bool useAbility(GameField& field, Coordinates coords)  override final;
};

#endif