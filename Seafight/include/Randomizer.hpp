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
    bool getRandomBool();
public:
    Randomizer();
    Coordinates getRandomCoordinates();
    void placeShipRandomly(GameField& field, Ship* ship);
};

#endif