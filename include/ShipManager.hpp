#pragma once
#include "Ship.hpp"

class ShipManager {

private:
    std::vector<Ship> ships;

public:
    ShipManager(std::vector<int> sizes);
    
    int getShipsAmount();
    Ship* getShip(int index);
    Ship& getShipByCoordinates(Coordinates coords);

};