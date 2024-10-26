#include "Game.hpp"

void Game::startGame(){
    GameField field1(10, 10);
    GameField field2(10, 10);
    std::vector<int> sizes = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
    ShipManager shipManager1(sizes);
    ShipManager shipManager2(sizes);
    ConsoleDisplayer displayer;
    InputHandler inputHandler;
    Randomizer randomizer;
    AbilityManager abilityManager(field2);

    for (int i = 0; i < shipManager1.getShipsAmount(); i++) {
       randomizer.placeShipRandomly(field1, shipManager1.getShip(i));
    }
    field2.setShip(Coordinates{ 1,1 }, shipManager2.getShip(0), true);
    field2.setShip(Coordinates{ 5,5 }, shipManager2.getShip(3), false);
    
    displayer.displayTwoFields(field1, field2);
    displayer.displayAbilities(abilityManager);

    while (!shipManager2.allShipsDestroyed()) {
        displayer.displayAttackOrAbilityChoice();
        int userChoice=inputHandler.handleAttackorAbility();
        try {
            switch (userChoice)
            {
            case 1: {
                displayer.displayWaitingCoordinatesInput();
                Coordinates attackCoords = inputHandler.handleCoordsInput();
                if (field2.attackCell(attackCoords)) {
                    randomizer.giveRandomAbilityCreator(abilityManager);
                }
                break;
            }
            case 2: {
                abilityManager.checkAbilitiesEmpty();
                if (abilityManager.getAbility(0).getCreatorType() == Abilities::RandomHit) {
                    if (abilityManager.useAbility({ 1,1 })) {
                        randomizer.giveRandomAbilityCreator(abilityManager);
                    }
                }
                else {
                    displayer.displayWaitingCoordinatesInput();
                    Coordinates abilityCoords = inputHandler.handleCoordsInput();
                    if (abilityManager.useAbility(abilityCoords)) {
                        randomizer.giveRandomAbilityCreator(abilityManager);
                    }
                }
                break;
            }
            default:
                displayer.displayUnknownCommandMessage();
                continue;
                break;
            }
        }
        catch (NoAbilitiesException& e) {
            displayer.displayException(e);
            continue;
        }
        catch (OutOfBoundsException& e) {
            displayer.displayException(e);
            continue;
        }
        displayer.displayTwoFields(field1, field2);
        displayer.displayAbilities(abilityManager);
    }
}