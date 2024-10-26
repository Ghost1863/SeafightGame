#include "AbilityManager.hpp"
#include "RandomHit.hpp"
#include "DoubleDamage.hpp"
#include "Scanner.hpp"

AbilityManager::AbilityManager(GameField& field) : field(field) {
    std::vector<AbilityCreator*> tempAbilities;
    tempAbilities.push_back(new RandomHitCreator());
    tempAbilities.push_back(new DoubleDamageCreator());
    tempAbilities.push_back(new ScannerCreator());

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
        delete abilities.front();
        abilities.pop();
    }
}

int AbilityManager::getAbilitiesSize() {
    return abilities.size();
}

AbilityCreator& AbilityManager::getAbility(int index) {
    std::queue<AbilityCreator*> tempQueue = abilities;
    for (int i = 0; i < index; ++i) {
        tempQueue.pop();
    }
    return *tempQueue.front();
}

void AbilityManager::addAbilityCreator(AbilityCreator* ability) {
    abilities.push(ability);
}

void AbilityManager::checkAbilitiesEmpty() {
    if (abilities.empty()) {
        throw NoAbilitiesException();
    }
}
bool AbilityManager::useAbility(Coordinates coords) {
    bool wasShipDestroyed = abilities.front()->createAbility()->useAbility(field, coords);
    delete abilities.front();
    abilities.pop();
    return wasShipDestroyed;
}

