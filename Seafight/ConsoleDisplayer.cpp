#include "ConsoleDisplayer.hpp"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

inline void ConsoleDisplayer::setColor(int foreground, int background , int attributes ) const noexcept {
	std::cout << "\033[" << attributes << ";" << foreground << ";" << background << "m";
}
inline void ConsoleDisplayer::resetColor() const noexcept {
	std::cout << "\033[0m";
}

inline void ConsoleDisplayer::drawHiddenCell() const noexcept {
	setColor(34);//BLUE
	std::cout << "~";
	resetColor();
}

inline void ConsoleDisplayer::drawShipSegment(SegmentStatus segmentStatus) const noexcept {
	switch (segmentStatus) {
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
	resetColor();
}
inline void ConsoleDisplayer::drawEmptyCell(CellValue value) const noexcept {
	switch (value) {
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
	resetColor();
}

inline void ConsoleDisplayer::drawCell(FieldCell cell, bool isShown) const noexcept {
	if (!isShown && cell.status == CellStatus::HIDDEN) {
		drawHiddenCell();
	}
	else {
		if (cell.value == CellValue::ShipSegment) {
			drawShipSegment(cell.shipSegment->status);
		}
		else {
			drawEmptyCell(cell.value);
		}
	}
}
void ConsoleDisplayer::drawBorder(int width) const noexcept {
	std::cout << " ";
	for (int i = 0; i < width; i++) {
		std::cout << "+ - ";
	}
	std::cout << "+ ";
}
void ConsoleDisplayer::drawLeftNumbers(int number) const noexcept {
	setColor(36);
	std::cout << number;
	resetColor();
	std::cout << " | ";
}
void ConsoleDisplayer::drawUpNumbers(int amount)  const noexcept {
	std::cout << "  ";
	for (int i = 0; i < amount; i++)
	{
		setColor(36);
		std::cout << "  " << static_cast<char>('A' + i) << " ";
	}
	resetColor();
}


void ConsoleDisplayer::displayField(GameField& gf, bool isShown) const noexcept {
	drawUpNumbers(gf.getWidth());
	std::cout << "\n ";
	for (int y = 0; y < gf.getHeight(); y++) {
		drawBorder(gf.getWidth());
		std::cout << "\n";
		drawLeftNumbers(y);
		for (int x = 0; x < gf.getWidth(); x++) {
			FieldCell& cell = gf.getFieldCell(Coordinates{ x,y });
			drawCell(cell, isShown);
			if (cell.coord.x == gf.getWidth() - 1) {
				std::cout << " | \n ";
			}
			else
				std::cout << " | ";
		}
	}
	drawBorder(gf.getWidth());
	std::cout << '\n';
}

void ConsoleDisplayer::displayTwoFields(GameField& gf1, GameField& gf2) const noexcept {
	drawUpNumbers(gf1.getWidth());
	std::cout << "\t\t";
	drawUpNumbers(gf2.getWidth());
	std::cout << "\n ";
	for (int y = 0; y < MIN(gf1.getHeight(),gf2.getHeight()); y++) {
		drawBorder(gf1.getWidth());
		std::cout << "\t\t ";
		drawBorder(gf2.getWidth());
		std::cout << "\n";
		drawLeftNumbers(y);

		for (int x = 0; x < gf1.getWidth(); x++) {
			FieldCell& cell = gf1.getFieldCell(Coordinates{ x,y });
			drawCell(cell, true);
			if (cell.coord.x == gf1.getWidth() - 1) {
				std::cout << " |\t\t";
				drawLeftNumbers(y);
				for (int x2 = 0; x2 < gf2.getWidth(); x2++) {
					FieldCell& cell2 = gf2.getFieldCell(Coordinates{ x2,y });
					drawCell(cell2, false);
					if (cell2.coord.x == gf2.getWidth() - 1) {
						std::cout << " | \n ";
					}
					else{
						std::cout << " | ";
					}
				}
			}
			else
				std::cout << " | ";
		}
	}
	drawBorder(gf1.getWidth());
	std::cout << "\t\t ";
	drawBorder(gf2.getWidth());
	std::cout << '\n';
}
void ConsoleDisplayer::displayShipsInfo(ShipManager& sm) const noexcept {
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

void ConsoleDisplayer::displayAbilities(AbilityManager& am) const noexcept {
	for (int i = 0; i < am.getAbilitiesAmount()+1; i++)
	{	
		std::cout << i << '.';
		switch (am.getAbility(i).getAbilityType())
		{
		case Abilities::DoubleDamage : std::cout << "Double Damage\n"; break;
		case Abilities::RandomHit : std::cout << "Random Hit\n"; break;
		case Abilities::Scanner : std::cout << "Scanner\n"; break;
		default:
			break;
		}
		
	}
}

void ConsoleDisplayer::displayException(std::exception& e) {
	std::cerr << "Exception caught: " << e.what() << std::endl;
}

