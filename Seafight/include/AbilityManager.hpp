#ifndef ABILITY_MANAGER_HPP
#define ABILITY_MANAGER_HPP

#include "Ability.hpp"
#include "NoAbilitiesException.hpp"
#include "AbilityCoordsRequiredException.hpp"
#include "AbilityCreator.hpp"
#include <queue>

class AbilityManager {
private:
    GameField& field;
    std::queue <Abilities> abilities;

public:
    AbilityManager(GameField& field);
    ~AbilityManager();

    int getAbilitiesSize();
    Abilities getAbility(int index);

    void checkAbilitiesEmpty();
    void addAbilityCreator(Abilities ability);
    AbilityResult useAbilityByCoords(Coordinates coords);
    AbilityResult useAbility();
};

#endif