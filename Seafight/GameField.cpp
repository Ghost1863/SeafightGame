#include "GameField.hpp"

GameField::GameField(int gf_width, int gf_height) {
	width = gf_width;
	height = gf_height;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			field.push_back(FieldCell(Coordinates{x,y}));
		}
	}
}

GameField::GameField(const GameField& other)
	: height(other.height), width(other.width), field(other.field) {}

GameField& GameField::operator=(const GameField& other) {
	if (this != &other) {
		width = other.width;
		height = other.height;
		field = other.field;
	}
	return *this;
}

GameField::GameField(GameField&& other)
	: height(other.height), width(other.width), field(std::move(other.field)) {
	other.width = 0;
	other.height = 0;
	other.field.clear();
}

GameField& GameField::operator=(GameField&& other) {
	if (this != &other) {
		width = other.width;
		height = other.height;
		field = std::move(other.field);
		other.width = 0;
		other.height = 0;
	}
	return *this;
}

int  GameField::getWidth() {
	return width;
}
int  GameField::getHeight() {
	return height;
}
FieldCell& GameField::getFieldCell(Coordinates coords) {
	return field[coords.x + coords.y * width];
}	

//std::vector<FieldCell*> GameField::getCellsForDoubleDamage(Coordinates coords) {
//	std::vector<FieldCell*> cells;
//	if (checkCurrentCoord(coords.x,coords.y)) {
//		cells.push_back(&getFieldCell(coords));
//	}
//	return cells;
//}
//std::vector<FieldCell*> GameField::getCellsForScanner(Coordinates coords) {
//	std::vector<FieldCell*> cells;
//	
//	return cells;
//}
//std::vector<FieldCell*> GameField::getCellsForRandomDamage() {
//	std::vector<FieldCell*> cells;
//	for (int y = 0; y < height; y++) {
//		for (int x = 0; x < width; x++) {
//			if (field[x + y * width].value == CellValue::ShipSegment &&
//				field[x + y * width].shipSegment->status!=SegmentStatus::DESTROYED) {
//				cells.push_back(&field[x + y * width]);
//			}
//		}
//	}
//	return cells;
//}

bool GameField::checkCurrentCoord(int x, int y) {
	if (x<0 || x>width - 1 || y<0 || y>height - 1) {
		return false;
	}
	return true;
}

bool GameField::checkCoordsAround(int x, int y) {
	if (checkCurrentCoord(x, y)) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (checkCurrentCoord(x + i, y + j)) {
					if (field[x + i + (y + j) * width].value == CellValue::ShipSegment) {
						return false;
					}
				}
			}
		}
	}
	else return false;

	return true;
}

void GameField::setShip(Coordinates coords, Ship* ship, bool isVertical) {
	if (!ship)
		return;
	bool ableToPlaceShip = true;
	if (checkCoordsAround(coords.x, coords.y)) {
		for (int i = 1; i < ship->getLength(); i++)
		{
			if (isVertical) {
				ableToPlaceShip = checkCoordsAround(coords.x, coords.y + i);
			}
			else {
				ableToPlaceShip = checkCoordsAround(coords.x + i, coords.y);
			}
			if (!ableToPlaceShip)
				return;
		}
		ship->getSegment(0)->coord = Coordinates{coords.x ,coords.y};
		field[coords.x + coords.y * width].shipSegment = ship->getSegment(0);
		field[coords.x + (coords.y) * width].value = CellValue::ShipSegment;
		field[coords.x + (coords.y) * width].ship = ship;
	}
	else {
		return;
	}

	ship->setIsVertical(isVertical);
	ship->setIsPlaced(true);

	if (isVertical) {
		//start point is up
		for (int i = 1; i < ship->getLength(); i++)
		{
			ship->getSegment(i)->coord = Coordinates{ coords.x ,coords.y + i };
			field[coords.x + (coords.y + i) * width].shipSegment = ship->getSegment(i);
			field[coords.x + (coords.y + i) * width].value = CellValue::ShipSegment;
			field[coords.x + (coords.y + i) * width].ship = ship;
		}
	}
	else {
		//start point is left
		for (int i = 1; i < ship->getLength(); i++)
		{
			ship->getSegment(i)->coord = Coordinates{ coords.x + i,coords.y };
			field[coords.x + i + (coords.y * width)].shipSegment = ship->getSegment(i);
			field[coords.x + i + (coords.y * width)].value = CellValue::ShipSegment;
			field[coords.x + i + (coords.y * width)].ship = ship;
		}
	}
}


bool GameField::attackCell(Coordinates coords) {
	if (!checkCurrentCoord(coords.x, coords.y)) {
		throw AttackOutOfBoundsException();
	}
	FieldCell& cell = field[coords.x + coords.y * width];
	cell.status = CellStatus::DISCLOSED;
	switch (cell.value)
	{
	case CellValue::Empty: {
		cell.value = CellValue::Miss;
		break;
	}
	case CellValue::ShipSegment:{
		if (cell.shipSegment->handleDamage()) {
			if (surroundShipIfDestroyed(&cell)) {
				return true;
			}
		}
		break;
	}
	default:
		break;
	}
	return false;
}
bool GameField::surroundShipIfDestroyed(FieldCell* cell) {
	std::vector <Coordinates> coords;
	for (int i = 0; i < cell->ship->getLength(); i++)
	{
		if (cell->ship->getSegment(i)->status == SegmentStatus::DESTROYED)
			coords.push_back(cell->ship->getSegment(i)->coord);
		else
			return false;
	}

	for (auto coord : coords) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (checkCurrentCoord(coord.x + i, coord.y + j)) {
					if (field[coord.x + i + (coord.y + j) * width].value != CellValue::ShipSegment) {
						field[coord.x + i + (coord.y + j) * width].value = CellValue::Miss;
						field[coord.x + i + (coord.y + j) * width].status = CellStatus::DISCLOSED;
					}
				}
			}
		}
	}
	cell->ship->setIsDestroyed(true);
	return true;
}
