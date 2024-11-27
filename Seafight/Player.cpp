#include "Player.hpp"

User::User(GameField& field, AbilityManager& abilityManager, ShipManager& sm,int currentDamage)
	: abilityManager(abilityManager), field(field), shipManager(sm),currentDamage(currentDamage) {}

User::User():field(GameField(10, 10)), shipManager({ 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 }),
abilityManager(AbilityManager()),currentDamage(1) {}

Bot::Bot(GameField& field, ShipManager& sm) : field(field),shipManager(sm) {}

Bot::Bot() : field(GameField(10, 10)), shipManager({ 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 }) {}

