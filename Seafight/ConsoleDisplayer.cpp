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
			drawShipSegment(cell.ship->getSegment(cell.segmentIndex)->status);
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
		//std::cout << "  " << static_cast<char>('A' + i) << " ";
		std::cout << "  " << i << " ";
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
			if (x == gf.getWidth() - 1) {
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
			if (x == gf1.getWidth() - 1) {
				std::cout << " |\t\t";
				drawLeftNumbers(y);
				for (int x2 = 0; x2 < gf2.getWidth(); x2++) {
					FieldCell& cell2 = gf2.getFieldCell(Coordinates{ x2,y });
					drawCell(cell2, true);
					if (x2 == gf2.getWidth() - 1) {
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
		Ship& ship = sm.getShip(i);
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
	std::cout << "Abilities available:\n";
	AbilityPrinter printer;
	if (am.getAbilitiesSize() == 0) {
		std::cout << "No abilities\n";
	}
	for (int i = 0; i < am.getAbilitiesSize(); i++)
	{	
		setColor(32);
		std::cout << i+1 << '.';
		resetColor();
		std::cout << am.getAbilityCreator(i).accept(&printer) << " ";
	}
	std::cout << "\n\n";
}

void ConsoleDisplayer::displayException(std::exception& e) {
	std::cerr << "Exception caught: " << e.what() << std::endl;
}

void ConsoleDisplayer::displayWaitingCoordinatesInput() {
	std::cout << "Enter coordinates with space: ";
}

void ConsoleDisplayer::displayGameOverMessage() {
	setColor(31);
	std::cout << R"(
  ________                        ________                     
 /  _____/_____    _____   ____   \_____  \___  __ ___________ 
/   \  ___\__  \  /     \_/ __ \   /   |   \  \/ // __ \_  __ \
\    \_\  \/ __ \|  Y Y  \  ___/  /    |    \   /\  ___/|  | \/
 \______  (____  /__|_|  /\___  > \_______  /\_/  \___  >__|   
        \/     \/      \/     \/          \/          \/       )";
	std::cout << std::endl;
	resetColor();
}

void ConsoleDisplayer::displayVictoryMessage(int round) {
	setColor(32);
	std::cout << "Bot was destroyed, Well Done!!!\n";
	resetColor();
	std::cout << "Starting round " << round << std::endl;
}

void ConsoleDisplayer::displayString(const std::string s)  const noexcept {
	std::cout << s << "\n";
}

void ConsoleDisplayer::displayColoredString(const std::string s, int num) {
	setColor(num);
	std::cout << s << "\n";
	resetColor();
}


