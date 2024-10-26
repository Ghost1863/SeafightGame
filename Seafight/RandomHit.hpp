#ifndef RANDOM_HIT_HPP
#define RANDOM_HIT_HPP

#include "Ability.hpp"

class RandomHit :public Ability {
private:
	GameField& field;
public:
	RandomHit(GameField& field) :field(field) {};
	AbilityResult useAbility()  override final;
};

#endif