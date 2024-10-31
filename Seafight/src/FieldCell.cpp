#include "FieldCell.hpp"

FieldCell::FieldCell(Coordinates coords) :
    coord(coords), status(CellStatus::HIDDEN),
    value(CellValue::Empty),segmentIndex(-1),ship(nullptr) {}
