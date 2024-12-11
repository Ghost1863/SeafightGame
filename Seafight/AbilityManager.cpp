#include "AbilityManager.hpp"


AbilityManager::AbilityManager(){};

void AbilityManager::initialiseStartCreators() {
    std::vector<AbilityCreator*> tempAbilities;
    tempAbilities.push_back(new DoubleDamageCreator());
    tempAbilities.push_back(new RandomHitCreator());
    tempAbilities.push_back(new ScannerCreator());

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine(seed);
    std::shuffle(tempAbilities.begin(), tempAbilities.end(), rng);

    for (auto ability : tempAbilities) {
        creators.push(ability);
    }
}

AbilityManager::~AbilityManager() {
    while (!creators.empty()) {
        creators.pop();
    }
}

int AbilityManager::getAbilitiesSize() {
    return creators.size();
}

AbilityCreator& AbilityManager::getAbilityCreator(int index) {
    checkAbilitiesEmpty();
    std::queue<AbilityCreator*> tempQueue = creators;
    for (int i = 0; i < index; ++i) {
        tempQueue.pop();
    }
    return *tempQueue.front();
}

void AbilityManager::addAbilityCreator(AbilityCreator* creator) {
    creators.push(creator);
}
void AbilityManager::addRandomAbilityCreator() {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_int_distribution<int> distribution(1, 3);
    int randomNumber = distribution(gen);
    switch (randomNumber)
    {   
    case 1:
        creators.push(new DoubleDamageCreator());
        break;
    case 2:
        creators.push(new RandomHitCreator());
        break;
    case 3:
        creators.push(new ScannerCreator());
        break;
    default:
        break;
    }
}

void AbilityManager::checkAbilitiesEmpty() {
    if (creators.empty()) {
        throw NoAbilitiesException();
    }
}

std::unique_ptr<AbilityResult> AbilityManager::useAbility(UserParams& params) {
    checkAbilitiesEmpty();
    Ability* curAbility = creators.front()->createAbility(params);
    std::unique_ptr<AbilityResult> result = curAbility->useAbility();
    delete(curAbility);
    return result;
}

void AbilityManager::popAbilityCreator(){
    checkAbilitiesEmpty();
    AbilityCreator* creator = creators.front();
    creators.pop();
    delete(creator);
}
