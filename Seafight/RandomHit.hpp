#ifndef RANDOM_HIT_HPP
#define RANDOM_HIT_HPP

#include "Ability.hpp"

class RandomHit :public Ability {
public:
	void useAbility(GameField& field, Coordinates coords)  override final;
	//Ability* createAbility(Abilities ability) override;
	virtual Abilities getAbilityType() override final;
};

#endif