#include "Randomizer.hpp"
#include "AbilityCreator.hpp"

void Randomizer::placeShipRandomly(GameField& field, Ship* ship) {
    while (!ship->getIsPlaced()) {
        try {
            Coordinates coord = getRandomCoordinates();
            bool isVertical = getRandomBool();
            field.setShip(coord, ship, isVertical);
        }
        catch (ShipsIntersectionException& e) {
            continue;
        }
    }
}

Randomizer::Randomizer()
    : gen(std::chrono::steady_clock::now().time_since_epoch().count()),
    distr(0, 9),
    distr_bool(0, 1) {}

Coordinates Randomizer::getRandomCoordinates() {
    int x = distr(gen);
    int y = distr(gen);
    return Coordinates{ x, y };
}

bool Randomizer::getRandomBool() {
    return static_cast<bool>(distr_bool(gen));
}

void Randomizer::giveRandomAbilityCreator(AbilityManager& abilityManager) {
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    int randomNumber = gen() % 3 + 1;
    switch (randomNumber)
    {
    case 1: {
        abilityManager.addAbilityCreator(Abilities::DoubleDamage);
        break;
    }
    case 2: {
        abilityManager.addAbilityCreator(Abilities::Scanner);
        break;
    }
    case 3: {
        abilityManager.addAbilityCreator(Abilities::RandomHit);
        break;
    }
    default:
        break;
    }

}