#include "Player.hpp"

User::User(GameField& field, AbilityManager& abilityManager, ShipManager& sm)
	: abilityManager(abilityManager), field(field), shipManager(sm){}

User::User():field(GameField(10, 10)), shipManager({4, 3, 3, 2, 2, 2, 1, 1, 1, 1 }),
abilityManager(AbilityManager()) {
	for (int i = 0; i < shipManager.getShipsAmount(); i++) {
		randomizer.placeShipRandomly(field, &shipManager.getShip(i));
	}
	abilityManager.initialiseStartCreators();
}

Bot::Bot(GameField& field, ShipManager& sm) : field(field),shipManager(sm) {}

Bot::Bot() : field(GameField(10, 10)), shipManager({ 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 }) {
	for (int i = 0; i < shipManager.getShipsAmount(); i++) {
		randomizer.placeShipRandomly(field, &shipManager.getShip(i));
	}
}

