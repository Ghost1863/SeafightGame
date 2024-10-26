#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "GameField.hpp"
#include<chrono>
#include<random>


class Ability {
public:
	virtual bool useAbility(GameField& field, Coordinates coords) = 0;
	virtual ~Ability() {}
};

#endif 
	