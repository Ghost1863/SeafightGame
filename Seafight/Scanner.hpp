#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "Ability.hpp"

class Scanner : public Ability {
private:
	Coordinates coords;
public:
	void useAbility(GameField& field, Coordinates coords) override final;
	//Ability* createAbility(Abilities ability) override;
	virtual Abilities getAbilityType() override final;
};

#endif