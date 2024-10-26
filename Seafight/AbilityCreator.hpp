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
private:
	GameField& field;
public:
	RandomHitCreator(GameField& field) :field(field) {};
	Ability* createAbility() override;
	Abilities getCreatorType() override;
};

class DoubleDamageCreator : public AbilityCreator {
private:
	GameField& field;
	Coordinates coords;
public:
	DoubleDamageCreator(GameField& field, Coordinates coords) : field(field), coords(coords) {};
	Ability* createAbility() override;
	Abilities getCreatorType() override;
};

class ScannerCreator : public AbilityCreator {
private:
	GameField& field;
	Coordinates coords;
public:
	ScannerCreator(GameField& field, Coordinates coords) : field(field), coords(coords) {};
	Ability* createAbility() override;
	Abilities getCreatorType() override;
};
#endif
