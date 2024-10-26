#include "AbilityManager.hpp"
#include "RandomHit.hpp"
#include "DoubleDamage.hpp"
#include "Scanner.hpp"

AbilityManager::AbilityManager(GameField& field) : field(field) {
    abilities.push_back(new RandomHitCreator());
    abilities.push_back(new DoubleDamageCreator());
    abilities.push_back(new ScannerCreator());
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine(seed);
    std::shuffle(std::begin(abilities), std::end(abilities), rng);
}

AbilityManager::~AbilityManager() {
    for (auto ability : abilities) {
        delete ability;
    }
}

int AbilityManager::getAbilitiesSize() {
    return abilities.size();
}

AbilityCreator& AbilityManager::getAbility(int index) {
    return *abilities[index];
}

void AbilityManager::addAbilityCreator(AbilityCreator* ability) {
    abilities.push_back(ability);
}

void AbilityManager::checkAbilitiesEmpty() {
    if (abilities.empty()) {
        throw NoAbilitiesException();
    }
}
bool AbilityManager::useAbility(Coordinates coords) {
        bool wasShipDestroyed=abilities[0]->createAbility()->useAbility(field, coords);
        abilities.erase(abilities.begin());
        return wasShipDestroyed;
}

