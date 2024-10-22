#ifndef ABILITY_MANAGER_HPP
#define ABILITY_MANAGER_HPP

#include "Ability.hpp"
#include "NoAbilitiesException.hpp"


class AbilityManager {
private:
    std::vector <Ability*> abilities;

public:
    AbilityManager();
    ~AbilityManager();

    int getAbilitiesAmount();
    Ability& getAbility(int index);

    void addAbility(Ability* ability);
    void useAbility(GameField& gf, Coordinates coords);
};

#endif