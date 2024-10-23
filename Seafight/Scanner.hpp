#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "Ability.hpp"

class Scanner : public Ability {
private:
	Coordinates coords;
public:
	bool useAbility(GameField& field, Coordinates coords) override final;
	virtual Abilities getAbilityType() override final;
};

#endif