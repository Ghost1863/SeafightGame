#include "Scanner.hpp"

Scanner::Scanner(GameField& field, Coordinates& coords) 
	:field(field), coords(coords),isCoordsRequired(false) {};


std::unique_ptr<AbilityResult> Scanner::useAbility() {
	std::vector <Coordinates> coordsForScan{ coords, Coordinates{ coords.x + 1,coords.y },
		Coordinates{ coords.x ,coords.y+1 }, Coordinates{ coords.x + 1,coords.y+1 }};
	for (auto& curCoords : coordsForScan) {
		if (!field.checkCurrentCoord(curCoords.x, curCoords.y)) {
			throw OutOfBoundsException();
		}
	}
	for (auto& curCoords : coordsForScan) {
		if (field.getFieldCell(curCoords).value == CellValue::ShipSegment)
			return std::make_unique<SegmentDetectedResult>();
	}
	return std::make_unique<SegmentNotFoundResult>();
}



