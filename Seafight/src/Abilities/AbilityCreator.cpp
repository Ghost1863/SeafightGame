#include "AbilityCreator.hpp"
#include "RandomHit.hpp"
#include "DoubleDamage.hpp"
#include "Scanner.hpp"


Ability* RandomHitCreator::createAbility(UserParams& params) {
	return new RandomHit(params.shipManager,params.field);
 }

bool RandomHitCreator::getIsCoordsRequired()
{
	return isCoordsRequired;
}

std::string RandomHitCreator::accept(AbilityVisitor* visitor)
{
	return visitor->visit(this);
}


Ability* DoubleDamageCreator::createAbility(UserParams& params) {
	return new DoubleDamage(params.currentDamage);
}

bool DoubleDamageCreator::getIsCoordsRequired() {
	return isCoordsRequired;
}

std::string DoubleDamageCreator::accept(AbilityVisitor* visitor)
{
	return visitor->visit(this);
}


Ability* ScannerCreator::createAbility(UserParams& params) {
	return new Scanner(params.field,params.coords);
}

bool ScannerCreator::getIsCoordsRequired() {
	return isCoordsRequired;
}

std::string ScannerCreator::accept(AbilityVisitor* visitor)
{
	return visitor->visit(this);
}


std::string  AbilityPrinter::visit(RandomHitCreator* creator) {
	return "Random Hit";
}

std::string  AbilityPrinter::visit(ScannerCreator* creator) {
	return "Scanner";
}

std::string  AbilityPrinter::visit(DoubleDamageCreator* creator) {
	return "Double Damage";
}
