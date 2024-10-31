#ifndef SHIP_MANAGER_HPP
#define SHIP_MANAGER_HPP

#include "Ship.hpp"

class ShipManager {

private:
    std::vector<Ship> ships;

public:
    ShipManager(std::vector<int> sizes);
    
    int getShipsAmount();
    bool allShipsDestroyed();

    Ship* getShip(int index);

};

#endif