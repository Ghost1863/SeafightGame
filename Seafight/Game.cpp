#include "Game.hpp"

void Game::startGame(){
    GameField field(10, 10);
    GameField field2(10, 10);
    std::vector<int> sizes = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
    ShipManager shipManager(sizes);
    ConsoleDisplayer displayer;
    Randomizer randomizer;
    AbilityManager abilityManager;

   // for (int i = 0; i < shipManager.getShipsAmount(); i++) {
       // randomizer.placeShipRandomly(field, shipManager.getShip(i));
    //}
    field2.setShip(Coordinates{ 1,1 }, shipManager.getShip(0), true);
    //field.setShip(Coordinates{ 5,5 }, shipManager.getShip(1), false);
    
    try {
        field2.attackCell(Coordinates{ 1,1 });
        field2.attackCell(Coordinates{ 1,2 });
        field2.attackCell(Coordinates{ 1,3 });
        field2.attackCell(Coordinates{ 1,4 });
        field2.attackCell(Coordinates{ 1,1 });
        field2.attackCell(Coordinates{ 1,2 });
        field2.attackCell(Coordinates{ 1,3 });
        //field2.attackCell(Coordinates{ 1,4 });
    }
    catch(AttackOutOfBoundsException& e){
        displayer.displayException(e);
    }

    auto& cell1 = field2.getFieldCell(Coordinates{ 1,1 });
    auto& cell2 = field2.getFieldCell(Coordinates{ 1,2 });
    std::vector<FieldCell*> cells;
    //cells.push_back(&cell1);
    //cells.push_back(&cell2);

    try {
       abilityManager.useAbility(field,{1,1});
       abilityManager.useAbility(field2, { 2,2 });
    }
    catch(NoAbilitiesException& e){
        displayer.displayException(e);
    }

    displayer.displayTwoFields(field, field2);
    displayer.displayAbilities(abilityManager);
}