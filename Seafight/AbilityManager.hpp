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

    int getAbilitiesSize();
    Ability& getAbility(int index);

    void checkAbilitiesEmpty();
    void addAbility(Ability* ability);
    bool useAbility(GameField& gf, Coordinates coords);
};

#endif