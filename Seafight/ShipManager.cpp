#include "ShipManager.hpp"

ShipManager::ShipManager(std::vector<int> sizes) {
    for (int i = 0; i < size(sizes); i++) {
        ships.push_back(Ship(sizes[i]));
    }
}

int ShipManager::getShipsAmount() {
    return ships.size();
}

bool ShipManager::allShipsDestroyed() {
    for (auto& ship : ships) {
        if (!ship.getIsPlaced()) {
            continue;
        }
        if (!ship.getIsDestroyed()) {
            return false;
        }
    }
    return true;
}

Ship* ShipManager::getShip(int index) {
    return &ships[index];
}

