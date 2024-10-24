#include "RandomHit.hpp"

bool RandomHit::useAbility(GameField& gf, Coordinates coords) {
	std::vector<Coordinates> coordsVector;
	for (int y = 0; y < gf.getHeight(); y++) {
		for (int x = 0; x < gf.getWidth(); x++) {
			Coordinates curCoords ={ x,y };
			if (gf.getFieldCell(curCoords).value == CellValue::ShipSegment &&
				gf.getFieldCell(curCoords).shipSegment->status != SegmentStatus::DESTROYED) {
				coordsVector.push_back(curCoords);
			}
		}
	}
	if (!coordsVector.empty()) {
		std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<> dis(0, coordsVector.size() - 1);
		int random_number = dis(gen);
		auto& cell = gf.getFieldCell(coordsVector[random_number]);
		cell.shipSegment->handleDamage();
		if (gf.surroundShipIfDestroyed(&cell)) {
			return true;
		}
	}
	return false;
}

Abilities RandomHit::getAbilityType() {
	return Abilities::RandomHit;
}