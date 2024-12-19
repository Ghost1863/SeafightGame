#include "Game.hpp"

Game::Game() :bot(std::make_shared<Bot>()), user(std::make_shared<User>()),
params(UserParams(bot->field, bot->shipManager)), currentRound(std::make_shared<int>(1)),
state(GameState(user, bot, currentRound)) {};



void Game::makeUserAbilityTurn() {
	std::unique_ptr<AbilityResult> result = user->abilityManager.useAbility(params);
	if (dynamic_cast<ShipDestroyedResult*>(result.get())) {
		user->abilityManager.addRandomAbilityCreator();
	}
	user->abilityManager.popAbilityCreator();
	for (auto observer : observers) {
		observer->userAbilityTurnEnd(result->getMessage());
	}

	//user win
	if (bot->shipManager.allShipsDestroyed()) {
		for (auto observer : observers) {
			observer->userWin();
			startNewRound();
		}
	}
}


void Game::makeUserAttackTurn() {
	for (int i = 0; i < params.currentDamage; i++)
	{
		if (params.field.attackCell(params.coords)) {
			user->abilityManager.addRandomAbilityCreator();
		}
	}
	params.currentDamage = 1;
		
	for (auto observer : observers) {
		observer->userAttackTurnEnd();
	}

	//user win
	if (bot->shipManager.allShipsDestroyed()) {
		for (auto observer : observers) {
			observer->userWin();
			startNewRound();
		}
	}
}

void Game::makeBotTurn() {;
	bool attackSuccess = false;
	while (!attackSuccess) {
		Coordinates coords = Randomizer().getRandomCoordinates();
		auto& cell = user->field.getFieldCell(coords);
		if (cell.value != CellValue::Miss || (cell.value == CellValue::ShipSegment
			&& cell.ship->getSegment(cell.segmentIndex)->status != SegmentStatus::DESTROYED)) {
			user->field.attackCell(coords);
			attackSuccess = true;
		}
	}
	for (auto observer : observers) {
		observer->botTurnEnd();
	}

	//bot win
	if (user->shipManager.allShipsDestroyed()) {
		for (auto observer : observers) {
			observer->botWin();
		}
		startNewGame();
	}
}

void Game::startNewGame() {
	*currentRound = 1;
	user = std::make_shared<User>();
}

void Game::startNewRound() {
	*currentRound += 1;
	bot = std::make_shared<Bot>();
}

void Game::saveGame() {
	GameSaver saver(this->state);
	saver.save();
}

void Game::loadGame() {
	GameLoader loader(this->state);
	loader.load();
	*currentRound = state.getCurrentRound();
	for (auto observer : observers) {
		observer->gameLoadSuccess();
	}
}

void Game::addObserver(GameObserver* observer) {
	if (observer != nullptr) {
		observers.push_back(observer);
	}
}

UserParams& Game::getUserParams() {
	return params;
}

GameState& Game::getState() {
	return state;
}
