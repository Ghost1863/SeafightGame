#include "ShipPlacer.hpp"

void ShipPlacer::placeShipRandomly(GameField& field, Ship* ship) {
    while (!ship->getIsPlaced()) {
        Coordinates coord = getRandomCoordinates();
        bool isVertical = getRandomBool();
        field.setShip(coord, ship, isVertical);
    }
}

ShipPlacer::ShipPlacer()
    : gen(std::chrono::steady_clock::now().time_since_epoch().count()),
    distr(0, 9),
    distr_bool(0, 1) {}

Coordinates ShipPlacer::getRandomCoordinates() {
    int x = distr(gen);
    int y = distr(gen);
    return Coordinates{ x, y };
}

bool  ShipPlacer::getRandomBool() {
    return static_cast<bool>(distr_bool(gen));
}