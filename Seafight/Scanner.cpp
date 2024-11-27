#include "Scanner.hpp"

Scanner::Scanner(GameField& field, Coordinates& coords) 
	:field(field), coords(coords),isCoordsRequired(false) {};


AbilityResult Scanner::useAbility() {
	std::vector <Coordinates> coordsForScan{ coords, Coordinates{ coords.x + 1,coords.y },
		Coordinates{ coords.x ,coords.y+1 }, Coordinates{ coords.x + 1,coords.y+1 }};
	for (auto& curCoords : coordsForScan) {
		if (!field.checkCurrentCoord(curCoords.x, curCoords.y)) {
			throw OutOfBoundsException();
		}
	}
	for (auto& curCoords : coordsForScan) {
		if (field.getFieldCell(curCoords).value == CellValue::ShipSegment)
			return AbilityResult::SegmentDetected;
	}
	return AbilityResult::SegmentNotFound;
}



