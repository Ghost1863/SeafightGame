#include "ConsoleDisplayer.hpp"

inline void ConsoleDisplayer::setColor(int foreground, int background , int attributes ) {
	std::cout << "\033[" << attributes << ";" << foreground << ";" << background << "m";
}
inline void ConsoleDisplayer::resetColor() {
	std::cout << "\033[0m";
}

void ConsoleDisplayer::displayField(GameField& gf, CellStatus status) {
	std::cout << " ";
	for (int i = 0; i <gf.getWidth(); i++)
	{
		setColor(36);
		std::cout << "  " << i << " ";
	}
	resetColor();
	std::cout << "\n ";
	for (int i = 0; i < gf.getWidth(); i++)
	{
		std::cout << "+ - ";
	}
	std::cout << "+ \n | ";
	for (auto& cell : gf.getField()) {

		if (status == CellStatus::HIDDEN && cell.status == CellStatus::HIDDEN) {
			setColor(34);//BLUE
			std::cout << "~";
		}
		else {
			if (cell.status == CellStatus::DISCLOSED || status== CellStatus::DISCLOSED)
				if (cell.value == CellValue::ShipSegment) {
					switch (cell.shipSegment->status) {
					case SegmentStatus::INTACT:
						setColor(32);//GREEN
						std::cout << "O";
						break;

					case SegmentStatus::DAMAGED:
						setColor(33);//YELLOW
						std::cout << "O";
						break;

					case SegmentStatus::DESTROYED:
						setColor(31);//RED
						std::cout << "O";
						break;
					default:
						break;
					}
				}
				else {
					switch (cell.value) {
					case CellValue::Empty:
						setColor(34);//BLUE
						std::cout << "#";
						break;
					case CellValue::Miss:
						setColor(31);//RED
						std::cout << "x";
						break;
					default:
						break;
					}
				}
		}
		resetColor();
		if (cell.coord.x == gf.getWidth() - 1) {
			std::cout << " | ";
			setColor(36);
			std::cout << cell.coord.y;
			resetColor();
		}
		else
			std::cout << " | ";
		if (cell.coord.x == gf.getWidth() - 1) {
			std::cout << "\n ";
			for (int i = 0; i < gf.getWidth(); i++)
			{
				std::cout << "+ - ";
			}
			std::cout << "+ ";
			if ((cell.coord.y) != gf.getHeight() - 1)
				std::cout << "\n | ";
		}
	}
	std::cout << '\n';
}

void ConsoleDisplayer::displayShipsInfo(ShipManager& sm) {
	std::cout << "\nships amount: " << sm.getShipsAmount() - 1 << "\n\n";
	for (int i = 0; i<sm.getShipsAmount();i++) {
		Ship& ship = *sm.getShip(i);
		std::cout << "length: " << ship.getLength() << "\n";
		for (int j = 0; j < ship.getLength(); j++)
		{
			std::cout << "Segment " << j << " coords x: " << ship.getSegment(j)->coord.x
				<< " y: " << ship.getSegment(j)->coord.y << " status:";
			switch (ship.getSegment(j)->status)
			{
			case SegmentStatus::INTACT:
				std::cout << "intact";
				break;
			case SegmentStatus::DAMAGED:
				std::cout << "damaged";
				break;
			case SegmentStatus::DESTROYED:
				std::cout << "destroyed";
				break;
			default:
				break;
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
}

