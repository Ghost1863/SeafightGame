#ifndef SHIP_SEGMENT_HPP
#define SHIP_SEGMENT_HPP

#include "Coordinates.hpp"

enum class SegmentStatus { INTACT, DAMAGED, DESTROYED };

struct ShipSegment {
    Coordinates coord;
    SegmentStatus status;

    ShipSegment();
    bool handleDamage();
};

#endif