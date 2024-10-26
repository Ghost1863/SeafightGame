#ifndef ABILITY_CREATOR_HPP
#define ABILITY_CREATOR_HPP
#include "Ability.hpp"

enum class Abilities { DoubleDamage, Scanner, RandomHit };

class AbilityCreator {
public:
	virtual Ability* createAbility() = 0;
	virtual Abilities getCreatorType() = 0;
	virtual ~AbilityCreator() {};
};

class RandomHitCreator : public AbilityCreator {
public:
	Ability* createAbility() override;
	Abilities getCreatorType() override;
};

class DoubleDamageCreator : public AbilityCreator {
public:
	Ability* createAbility() override;
	Abilities getCreatorType() override;
};

class ScannerCreator : public AbilityCreator {
public:
	Ability* createAbility() override;
	Abilities getCreatorType() override;
};
#endif
