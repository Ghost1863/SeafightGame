#include "Scanner.hpp"

void Scanner::useAbility(GameField& gf, Coordinates coords) {
	std::vector <Coordinates> coordsForScan {coords, Coordinates{ coords.x + 1,coords.y },
		Coordinates{ coords.x ,coords.y+1 }, Coordinates{ coords.x + 1,coords.y+1 }};
	for (auto& curCoords : coordsForScan) {
		if (gf.checkCurrentCoord(curCoords.x, curCoords.y)) {
			gf.getFieldCell(curCoords).status = CellStatus::DISCLOSED;
		}
	}
}

//Ability* Scanner::createAbility(Abilities ability) {
//	return new Scanner;
//}

Abilities Scanner::getAbilityType() {
	return Abilities::Scanner;
}
