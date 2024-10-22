#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "GameField.hpp"
#include<chrono>
#include<random>

enum class Abilities{DoubleDamage,Scanner, RandomHit};

class Ability {
public:
	virtual void useAbility(GameField& field,Coordinates coords) = 0;
	//virtual Ability* createAbility(Abilities ability) = 0 ;
	virtual Abilities getAbilityType()=0;
	virtual ~Ability() {}
};

#endif 
	