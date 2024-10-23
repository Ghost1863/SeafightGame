#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "GameField.hpp"
#include "AttackOutOfBoundsException.hpp"
#include<chrono>
#include<random>

enum class Abilities{DoubleDamage,Scanner, RandomHit};

class Ability {
public:
	virtual bool useAbility(GameField& field,Coordinates coords) = 0;
	virtual Abilities getAbilityType()=0;
	virtual ~Ability() {}
};

#endif 
	