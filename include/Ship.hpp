#pragma once
#include "Structures.hpp"
#include <string>
#include <vector>


class Ship {

private:
    int length;
    bool isPlaced = false;
    bool isVertical = false;
    std::vector<ShipSegment> segments;

public:
    Ship(int shipLength);

    int getLength();
    ShipSegment* getSegment(int index);
    bool getIsPlaced();
    bool getIsVertical();

    void setIsPlaced(bool isPlaced);
    void setIsVertical(bool isVertical);

    void attackHandling();
};