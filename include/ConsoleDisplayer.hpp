#include "GameField.hpp"
#include "ShipManager.hpp"

class ConsoleDisplayer {

private:
	inline void setColor(int foreground, int background = 40, int attributes = 0);
	inline void resetColor();

public:
	void displayField(GameField& gf, CellStatus status);
	void displayShipsInfo(ShipManager& sm);	
};