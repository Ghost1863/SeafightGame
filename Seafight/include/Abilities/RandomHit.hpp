#ifndef RANDOM_HIT_HPP
#define RANDOM_HIT_HPP

#include "Ability.hpp"

class RandomHit :public Ability {
private:
	ShipManager& shipManager;
	GameField& field;
	bool isCoordsRequired;
public:
	RandomHit(ShipManager& shipManager, GameField& field);
	std::unique_ptr<AbilityResult> useAbility()  override final;
};

#endif