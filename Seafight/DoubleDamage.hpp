#ifndef DOUBLE_DAMAGE_HPP
#define DOUBLE_DAMAGE_HPP

#include "Ability.hpp"

class DoubleDamage : public Ability {
private:
	Coordinates coords;
public:
	void useAbility(GameField& field, Coordinates coords) override final;
	//Ability* createAbility(Abilities ability) override;
	virtual Abilities getAbilityType() override final;
};

#endif