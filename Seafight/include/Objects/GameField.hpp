#ifndef GAME_FIELD_HPP
#define GAME_FIELD_HPP

#include "Ship.hpp"
#include "FieldCell.hpp"
#include "ShipSegment.hpp"
#include "OutOfBoundsException.hpp"
#include "ShipsIntersectionException.hpp"
#include <vector>
#include <iostream>


class GameField {

private:
	int width;
	int height;
	std::vector<FieldCell> field;

public:

	GameField() : width(0), height(0) {};
	GameField(int width, int height);
	GameField(const GameField& other);
	GameField& operator=(const GameField& other);
	GameField(GameField&& other);
	GameField& operator=(GameField&& other);
		
	int getWidth();
	int getHeight();
	FieldCell& getFieldCell(Coordinates coords);
	
	bool checkCurrentCoord(int x, int y);
	bool checkCoordsAround(int x, int y);
	void setShip(Coordinates coords, Ship* ship, bool isVertical);
	bool attackCell(Coordinates coords);
	bool surroundShipIfDestroyed(FieldCell* cell);
};

#endif