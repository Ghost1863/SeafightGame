#ifndef SHIP_MANAGER_HPP
#define SHIP_MANAGER_HPP
#include "nlohmann/json.hpp"
#include "Ship.hpp"

class ShipManager {

private:
    std::vector<Ship> ships;

public:
    ShipManager() : ships({}) {};
    ShipManager(std::vector<int> sizes);

    int getShipsAmount();
    bool allShipsDestroyed();
    void addShip(Ship& ship);
    Ship& getShip(int index);

};

#endif