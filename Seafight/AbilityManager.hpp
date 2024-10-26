#ifndef ABILITY_MANAGER_HPP
#define ABILITY_MANAGER_HPP

#include "Ability.hpp"
#include "NoAbilitiesException.hpp"
#include "AbilityCreator.hpp"


class AbilityManager {
private:
    GameField& field;
    std::vector <AbilityCreator*> abilities;

public:
    AbilityManager(GameField& field);
    ~AbilityManager();

    int getAbilitiesSize();
    AbilityCreator& getAbility(int index);

    void checkAbilitiesEmpty();
    void addAbilityCreator(AbilityCreator* ability);
    bool useAbility(Coordinates coords);
};

#endif