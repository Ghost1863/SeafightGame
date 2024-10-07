#include "GameField.hpp"
#include <random>
#include <chrono>


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
std::vector<FieldCell>  GameField::getField() {
	return field;
}

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
		}
	}
	else {
		//start point is left
		for (int i = 1; i < ship->getLength(); i++)
		{
			ship->getSegment(i)->coord = Coordinates{ coords.x + i,coords.y };
			field[coords.x + i + (coords.y * width)].shipSegment = ship->getSegment(i);
			field[coords.x + i + (coords.y * width)].value = CellValue::ShipSegment;
		}
	}
}

void GameField::attackCell(Coordinates coords) {
	if (!checkCurrentCoord(coords.x, coords.y)) {
		return;
	}
	FieldCell& cell = field[coords.x + coords.y * width];
	cell.status = CellStatus::DISCLOSED;

	switch (cell.value)
	{
	case CellValue::Empty:
		cell.value = CellValue::Miss;
		break;
	case CellValue::ShipSegment: {
		if (cell.shipSegment->status == SegmentStatus::INTACT) {
			cell.shipSegment->status = SegmentStatus::DAMAGED;
		}
		else if(cell.shipSegment->status==SegmentStatus::DAMAGED){
			cell.shipSegment->status = SegmentStatus::DESTROYED;
		}
		break;
	}
	default:
		break;
	}
}