#include "AbilityCreator.hpp"
#include "RandomHit.hpp"
#include "DoubleDamage.hpp"
#include "Scanner.hpp"


RandomHitCreator::RandomHitCreator(GameField& field)
	: field(field){};

Ability* RandomHitCreator::createAbility() {
	return new RandomHit(field);
 }

Abilities RandomHitCreator::getCreatorType() {
	return  Abilities::RandomHit;
}


DoubleDamageCreator::DoubleDamageCreator(GameField& field, Coordinates coords)
	: field(field), coords(coords) {};

Ability* DoubleDamageCreator::createAbility() {
	return new DoubleDamage(field,coords);
}

Abilities DoubleDamageCreator::getCreatorType() {
	return  Abilities::DoubleDamage;
}



ScannerCreator::ScannerCreator(GameField& field, Coordinates coords)
	: field(field), coords(coords) {};

Ability* ScannerCreator::createAbility() {
	return new Scanner(field,coords);
}

Abilities ScannerCreator::getCreatorType() {
	return  Abilities::Scanner;
}
