#include "AbilityCreator.hpp"
#include "RandomHit.hpp"
#include "DoubleDamage.hpp"
#include "Scanner.hpp"

Ability* RandomHitCreator::createAbility() {
	return new RandomHit(field);
 }

Abilities RandomHitCreator::getCreatorType() {
	return  Abilities::RandomHit;
}

Ability* DoubleDamageCreator::createAbility() {
	return new DoubleDamage(field,coords);
}

Abilities DoubleDamageCreator::getCreatorType() {
	return  Abilities::DoubleDamage;
}

Ability* ScannerCreator::createAbility() {
	return new Scanner(field,coords);
}

Abilities ScannerCreator::getCreatorType() {
	return  Abilities::Scanner;
}
