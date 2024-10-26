#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "Ability.hpp"

class Scanner : public Ability {
private:
	GameField& field;
	Coordinates coords;
public:
	Scanner(GameField& field, Coordinates coords) :field(field), coords(coords) {};
	AbilityResult useAbility() override final;
};

#endif