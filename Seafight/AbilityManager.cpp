#include "AbilityManager.hpp"


AbilityManager::AbilityManager(GameField& field) : field(field) {
    std::vector<Abilities> tempAbilities;
    tempAbilities.push_back(Abilities::DoubleDamage);
    tempAbilities.push_back(Abilities::RandomHit);
    tempAbilities.push_back(Abilities::Scanner);

    // Перемешиваем вектор
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine(seed);
    std::shuffle(tempAbilities.begin(), tempAbilities.end(), rng);

    // Перемещаем элементы из вектора в очередь
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
    Abilities curAbility = abilities.front();
    abilities.pop();
    switch (curAbility)
    {
    case Abilities::DoubleDamage: {
        return (new DoubleDamageCreator(field, coords))->createAbility()->useAbility();
        break;
    }
    case Abilities::Scanner: {
        return (new ScannerCreator(field, coords))->createAbility()->useAbility();
        break;
    }
    default:
        break;
    }
}
AbilityResult AbilityManager::useAbility() {
    Abilities curAbility = abilities.front();
    abilities.pop();
    if (curAbility == Abilities::RandomHit) {
        return (new RandomHitCreator(field))->createAbility()->useAbility();
    }
    else {
        throw AbilityCoordsRequiredException();
    }
    
}
