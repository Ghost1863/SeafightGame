#include "ShipManager.hpp"
#include <iostream>

ShipManager::ShipManager(std::vector<int> sizes) {
    for (int i = 0; i < size(sizes); i++) {
        ships.push_back(Ship(sizes[i]));
    }
}

int ShipManager::getShipsAmount() {
    return ships.size();
}

Ship* ShipManager::getShip(int index) {
    return &ships[index];
}


Ship& ShipManager::getShipByCoordinates(Coordinates coords) {
    for (auto& ship : ships) {
        for (int i = 0; i < ship.getLength(); i++)
        {
            if (ship.getSegment(i)->coord == coords) {
                return ship;
            }
        }
    }
}
