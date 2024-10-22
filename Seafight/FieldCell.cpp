#include "FieldCell.hpp"

FieldCell::FieldCell(Coordinates coords) :
    coord(coords), status(CellStatus::HIDDEN),
    value(CellValue::Empty), shipSegment(nullptr),ship(nullptr) {}
