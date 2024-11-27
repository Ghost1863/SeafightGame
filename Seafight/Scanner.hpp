#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "Ability.hpp"

class Scanner : public Ability {
private:
	GameField& field;
	Coordinates coords;
	bool isCoordsRequired;
public:
	Scanner(GameField& field, Coordinates& coords);
	AbilityResult useAbility() override final;
};

#endif