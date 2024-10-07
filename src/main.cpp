#include "GameField.hpp"
#include "ShipManager.hpp"
#include "ConsoleDisplayer.hpp"
#include "ShipPlacer.hpp"

int main()
{
    GameField field(10, 10);
    std::vector<int> sizes = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
    ShipManager shipManager(sizes);
    ConsoleDisplayer displayer;
    ShipPlacer shipPlacer;

    for (int i = 0; i < shipManager.getShipsAmount(); i++){
        shipPlacer.placeShipRandomly(field, shipManager.getShip(i));
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
           field.attackCell(Coordinates{ i,j });
        }
    }
    displayer.displayShipsInfo(shipManager);
    displayer.displayField(field,CellStatus::DISCLOSED);
}