#include "RandomHit.hpp"

AbilityResult RandomHit::useAbility() {
	std::vector<Coordinates> coordsVector;
	for (int y = 0; y < field.getHeight(); y++) {
		for (int x = 0; x < field.getWidth(); x++) {
			Coordinates curCoords ={ x,y };
			if (field.getFieldCell(curCoords).value == CellValue::ShipSegment &&
				field.getFieldCell(curCoords).shipSegment->status != SegmentStatus::DESTROYED) {
				coordsVector.push_back(curCoords);
			}
		}
	}
	if (!coordsVector.empty()) {
		std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<> dis(0, coordsVector.size() - 1);
		int random_number = dis(gen);
		auto& cell = field.getFieldCell(coordsVector[random_number]);
		cell.shipSegment->handleDamage();
		if (field.surroundShipIfDestroyed(&cell)) {
			return AbilityResult::ShipDestroyed;
		}
	}
	return AbilityResult::ShipNotDestroyed;
}
