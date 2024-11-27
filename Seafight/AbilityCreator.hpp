#ifndef ABILITY_CREATOR_HPP
#define ABILITY_CREATOR_HPP
#include "Ability.hpp"

class AbilityVisitor;

class AbilityCreator {
public:
	virtual Ability* createAbility(UserParams& params) = 0;
	virtual bool getIsCoordsRequired() = 0;
	virtual std::string accept(AbilityVisitor* visitor) = 0;
	virtual ~AbilityCreator() {};
};

class RandomHitCreator : public AbilityCreator {
private:
	bool isCoordsRequired;
public:
	RandomHitCreator() : isCoordsRequired(false) {};
	Ability* createAbility(UserParams& params) override;
	bool getIsCoordsRequired() override;
	std::string  accept(AbilityVisitor* visitor) ;
};

class DoubleDamageCreator : public AbilityCreator {
private:
	bool isCoordsRequired;
public:
	DoubleDamageCreator() : isCoordsRequired(false) {};
	Ability* createAbility(UserParams& params) override;
	bool getIsCoordsRequired() override;
	std::string accept(AbilityVisitor* visitor) ;
};

class ScannerCreator : public AbilityCreator {
private:
	bool isCoordsRequired;
public:
	ScannerCreator() : isCoordsRequired(true) {};
	Ability* createAbility(UserParams& params) override;
	bool getIsCoordsRequired() override;
	std::string accept(AbilityVisitor* visitor) ;
};


class AbilityVisitor {
public:
	virtual std::string visit(RandomHitCreator* creator) = 0;
	virtual std::string visit(DoubleDamageCreator* creator) = 0;
	virtual std::string visit(ScannerCreator* creator) = 0;
};

class AbilityPrinter : public AbilityVisitor {
public:
	std::string visit(RandomHitCreator* creator) override;
	std::string visit(DoubleDamageCreator* creator) override;
	std::string visit(ScannerCreator* creator) override;
};
#endif
