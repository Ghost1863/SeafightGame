#include "AbilityManager.hpp"
#include "RandomHit.hpp"
#include "DoubleDamage.hpp"
#include "Scanner.hpp"

AbilityManager::AbilityManager() {
 
    abilities.push_back(new DoubleDamage);
    abilities.push_back(new Scanner);
    abilities.push_back(new RandomHit);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine(seed);
   // std::shuffle(std::begin(abilities), std::end(abilities), rng);
}

AbilityManager::~AbilityManager() {
    for (auto ability : abilities) {
        delete ability;
    }
}

int AbilityManager::getAbilitiesAmount() {
    return abilities.size() - 1;
}

Ability& AbilityManager::getAbility(int index) {
    return *abilities[index];
}

void AbilityManager::addAbility(Ability* ability) {
    abilities.push_back(ability);
}

void AbilityManager::useAbility(GameField& gf, Coordinates coords) {
    if (!abilities.empty()) {
        abilities[0]->useAbility(gf,coords);
        abilities.erase(abilities.begin());
    }
    else throw NoAbilitiesException();
}
