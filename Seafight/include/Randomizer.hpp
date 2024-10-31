#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include "GameField.hpp"
#include "AbilityManager.hpp"
#include <random>
#include <chrono>

class Randomizer {
private:
    std::mt19937 gen;
    std::uniform_int_distribution<int> distr;
    std::uniform_int_distribution<int> distr_bool;

    Coordinates getRandomCoordinates();
    bool getRandomBool();

public:
    Randomizer();
    void placeShipRandomly(GameField& field, Ship* ship);
    void giveRandomAbilityCreator(AbilityManager& abilityManager);
};

#endif