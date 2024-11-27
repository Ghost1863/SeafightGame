#include "RandomHit.hpp"

RandomHit::RandomHit(ShipManager& shipManager, GameField& field) :
	shipManager(shipManager),field(field),isCoordsRequired(false) {};

AbilityResult RandomHit::useAbility() {
	std::vector<ShipSegment*> segmentsVector;
	for (int i = 0; i < shipManager.getShipsAmount(); i++) {
		for (int j = 0; j<shipManager.getShip(i).getLength();j++) {
			if (shipManager.getShip(i).getSegment(j)->status != SegmentStatus::DESTROYED) {
				segmentsVector.push_back(shipManager.getShip(i).getSegment(j));
			}
		}
	}
	if (!segmentsVector.empty()) {
		std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<> dis(0, segmentsVector.size() - 1);
		int random_number = dis(gen);
		
		auto& cell = field.getFieldCell(segmentsVector[random_number]->coord);
		cell.ship->getSegment(cell.segmentIndex)->handleDamage();
		if (field.surroundShipIfDestroyed(&cell)) {
			return AbilityResult::ShipDestroyed;
		}
	}
	return AbilityResult::ShipNotDestroyed;
}

