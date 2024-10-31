#include "AbilityManager.hpp"


AbilityManager::AbilityManager(GameField& field) : field(field) {
    std::vector<Abilities> tempAbilities;
    tempAbilities.push_back(Abilities::DoubleDamage);
    tempAbilities.push_back(Abilities::RandomHit);
    tempAbilities.push_back(Abilities::Scanner);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine(seed);
    std::shuffle(tempAbilities.begin(), tempAbilities.end(), rng);

    for (auto ability : tempAbilities) {
        abilities.push(ability);
    }
}

AbilityManager::~AbilityManager() {
    while (!abilities.empty()) {
        abilities.pop();
    }
}

int AbilityManager::getAbilitiesSize() {
    return abilities.size();
}

Abilities AbilityManager::getAbility(int index) {
    std::queue<Abilities> tempQueue = abilities;
    for (int i = 0; i < index; ++i) {
        tempQueue.pop();
    }
    return tempQueue.front();
}

void AbilityManager::addAbilityCreator(Abilities ability) {
    abilities.push(ability);
}

void AbilityManager::checkAbilitiesEmpty() {
    if (abilities.empty()) {
        throw NoAbilitiesException();
    }
}
AbilityResult AbilityManager::useAbilityByCoords(Coordinates coords) {
    switch (abilities.front())
    {
    case Abilities::DoubleDamage: {
        Ability* curAbility = DoubleDamageCreator(field,coords).createAbility();
        AbilityResult result=curAbility->useAbility();
        delete(curAbility);
        abilities.pop();
        return result;
        break;
    }
    case Abilities::Scanner: {
        Ability* curAbility = ScannerCreator(field, coords).createAbility();
        AbilityResult result =ScannerCreator(field, coords).createAbility()->useAbility();
        delete(curAbility);
        abilities.pop();
        return result;
        break;
    }
    default:
        break;
    }
}
AbilityResult AbilityManager::useAbility() {
    if (abilities.front() == Abilities::RandomHit) {
        Ability* curAbility = RandomHitCreator(field).createAbility();
        AbilityResult result = curAbility->useAbility();
        delete(curAbility);
        abilities.pop();
        return result;
    }

}
