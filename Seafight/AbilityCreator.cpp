#include "AbilityCreator.hpp"
#include "RandomHit.hpp"
#include "DoubleDamage.hpp"
#include "Scanner.hpp"

Ability* RandomHitCreator::createAbility() {
	return new RandomHit();
 }

Abilities RandomHitCreator::getCreatorType() {
	return  Abilities::RandomHit;
}

Ability* DoubleDamageCreator::createAbility() {
	return new DoubleDamage();
}

Abilities DoubleDamageCreator::getCreatorType() {
	return  Abilities::DoubleDamage;
}

Ability* ScannerCreator::createAbility() {
	return new Scanner();
}

Abilities ScannerCreator::getCreatorType() {
	return  Abilities::Scanner;
}
