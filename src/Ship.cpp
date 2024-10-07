#include "Ship.hpp"
#include <iomanip>


Ship::Ship(int shipLength) : length(shipLength) {
    for (int i = 0; i < shipLength; i++) {
        segments.push_back(ShipSegment());
    }
}

int Ship::getLength() {
    return length;
}

bool Ship::getIsVertical() {
    return isVertical;
}

ShipSegment* Ship::getSegment(int index) {
    return &segments[index];
}

bool Ship::getIsPlaced() {
    return isPlaced;
}

void Ship::setIsPlaced(bool isPlaced) {
    this->isPlaced = isPlaced;
}

void Ship::setIsVertical(bool isVertical) {
    this->isVertical = isVertical;
}   