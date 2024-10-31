#ifndef FIELD_CELL_HPP
#define FIELD_CELL_HPP

#include "Coordinates.hpp"
#include "ShipSegment.hpp"
#include "Ship.hpp"

enum class CellStatus { HIDDEN, DISCLOSED };
enum class CellValue { Empty, Miss, ShipSegment };

struct FieldCell {
    Coordinates coord;
    CellStatus status;
    CellValue value;
    Ship* ship;
    int segmentIndex;

    FieldCell(Coordinates coords);
};

#endif