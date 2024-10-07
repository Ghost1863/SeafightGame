#pragma once
#include "GameField.hpp"
#include <random>
#include <chrono>

class ShipPlacer {
private:
    std::mt19937 gen;
    std::uniform_int_distribution<int> distr;
    std::uniform_int_distribution<int> distr_bool;

    Coordinates getRandomCoordinates();
    bool getRandomBool();

public:
    ShipPlacer();
    void placeShipRandomly(GameField& field, Ship* ship);
};