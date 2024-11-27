#ifndef ABILITY_MANAGER_HPP
#define ABILITY_MANAGER_HPP

#include "Ability.hpp"
#include "NoAbilitiesException.hpp"
#include "AbilityCreator.hpp"
#include "UserParams.hpp"
#include <queue>

class AbilityManager {
private:
    std::queue <AbilityCreator*> creators;
public:
    AbilityManager();
    ~AbilityManager();

    int getAbilitiesSize();
    AbilityCreator& getAbilityCreator(int index);

    void initialiseStartCreators();
    void checkAbilitiesEmpty();
    void addRandomAbilityCreator();
    void addAbilityCreator(AbilityCreator* creator);
    void popAbilityCreator();
    AbilityResult useAbility(UserParams& params); 
};

#endif