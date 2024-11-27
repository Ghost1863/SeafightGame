#include "ShipSegment.hpp"

ShipSegment::ShipSegment() : coord({ 0, 0 }), status(SegmentStatus::INTACT) {}

bool ShipSegment::handleDamage() {
    if (this->status == SegmentStatus::INTACT) {
        this->status = SegmentStatus::DAMAGED;
        return false;
    }
    else if (this->status == SegmentStatus::DAMAGED) {
        this->status = SegmentStatus::DESTROYED;
        return true;
    }
}

