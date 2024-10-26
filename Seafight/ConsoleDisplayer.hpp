#ifndef CONSOLE_DISPLAYER_HPP
#define CONSOLE_DISPLAYER_HPP

#include "GameField.hpp"
#include "ShipManager.hpp"
#include "AbilityManager.hpp"
#include <exception>

class ConsoleDisplayer {

private:
	inline void setColor(int foreground, int background = 40, int attributes = 0) const noexcept;
	inline void resetColor() const noexcept;

	inline void drawHiddenCell() const noexcept;
	inline void drawShipSegment(SegmentStatus segmentStatus) const noexcept;
	inline void drawEmptyCell(CellValue value) const noexcept;
	inline void drawCell(FieldCell cell, bool isShown) const noexcept;

	void drawBorder(int width) const noexcept;
	void drawLeftNumbers(int number) const noexcept;
	void drawUpNumbers(int amount) const noexcept;


public:
	void displayField(GameField& gf, bool isShown) const noexcept;
	void displayTwoFields(GameField& gf1, GameField& gf2) const noexcept;
	void displayShipsInfo(ShipManager& sm)const noexcept;
	void displayAbilities(AbilityManager& am) const noexcept;
	void displayException(std::exception& e);
	void displayAttackOrAbilityChoice();
	void displayWaitingCoordinatesInput();
	void displayUnknownCommandMessage();
	void displaySegmentWasFoundMessage();
	void displaySegmentWasNotFoundMessage();
};

#endif