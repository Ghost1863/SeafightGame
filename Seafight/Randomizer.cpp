#include "Randomizer.hpp"
#include "Scanner.hpp"
#include "DoubleDamage.hpp"
#include "RandomHit.hpp"

void Randomizer::placeShipRandomly(GameField& field, Ship* ship) {
    while (!ship->getIsPlaced()) {
        Coordinates coord = getRandomCoordinates();
        bool isVertical = getRandomBool();
        field.setShip(coord, ship, isVertical);
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

void Randomizer::giveRandomAbility(AbilityManager& abilityManager) {
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    int randomNumber = gen() % 3 + 1;
    switch (randomNumber)
    {
    case 1: {
        abilityManager.addAbility(new DoubleDamage);
        break;
    }
    case 2: {
        abilityManager.addAbility(new Scanner);
        break;
    }
    case 3: {
        abilityManager.addAbility(new RandomHit);
        break;
    }
    default:
        break;
    }

}