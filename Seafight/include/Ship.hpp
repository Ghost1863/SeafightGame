#ifndef SHIP_HPP
#define SHIP_HPP

#include "ShipSegment.hpp"
#include <string>
#include <vector>


class Ship {

private:
    int length;
    bool isPlaced = false;
    bool isVertical = false;
    bool isDestroyed = false;
    std::vector<ShipSegment> segments;

public:
    Ship(int shipLength);

    int getLength();
    ShipSegment* getSegment(int index);
    bool getIsPlaced();
    bool getIsVertical();
    bool getIsDestroyed();

    void setIsPlaced(bool isPlaced);
    void setIsVertical(bool isVertical);
    void setIsDestroyed(bool isDestroyed);
};

#endif