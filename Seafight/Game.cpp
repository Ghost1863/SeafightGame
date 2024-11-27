#include "Game.hpp"
#include "Player.hpp"
#include "UserParams.hpp"

Game::Game() {
	isUserTurn = true;
	currentRound = 1;
	this->user = std::make_shared<User>();
	this->bot = std::make_shared<Bot>();
	this->state= new GameState(user, bot, currentRound);

	user->abilityManager.initialiseStartCreators();
	for (int i = 0; i < user->shipManager.getShipsAmount(); i++) {
		Randomizer().placeShipRandomly(user->field, &user->shipManager.getShip(i));
	}
	for (int i = 0; i < bot->shipManager.getShipsAmount(); i++) {
		Randomizer().placeShipRandomly(bot->field, &bot->shipManager.getShip(i));
	}
}

void Game::makeUserAbilityTurn() {
	Coordinates userCoords{ -1,-1 };
	UserParams params(bot->field, bot->shipManager, userCoords,user->currentDamage);
	ConsoleDisplayer displayer;
	InputHandler inputHandler;
	bool abilitySuccess = false;

	while (!abilitySuccess) {
		try {
			if (user->abilityManager.getAbilityCreator(0).getIsCoordsRequired()) {
				displayer.displayWaitingCoordinatesInput();
				params.coords = inputHandler.handleCoordsInput();
			}
			AbilityResult result = user->abilityManager.useAbility(params);
			switch (result)
			{
			case AbilityResult::ShipDestroyed:
				user->abilityManager.addRandomAbilityCreator();
				break;
			case AbilityResult::SegmentDetected:
				displayer.displaySegmentWasFoundMessage();
				break;
			case AbilityResult::SegmentNotFound:
				displayer.displaySegmentWasNotFoundMessage();
				break;
			default:
				break;
			}
			user->abilityManager.popAbilityCreator();
			abilitySuccess = true;
		}
		catch (NoAbilitiesException& e) {
			displayer.displayException(e);
			break;
		}
		catch (OutOfBoundsException& e) {
			displayer.displayException(e);
		}
	}
}

void Game:: makeUserAttackTurn() {
	ConsoleDisplayer displayer;
	InputHandler inputHandler;
	Coordinates userCoords{ -1,-1 };
	UserParams params(bot->field, bot->shipManager, userCoords,user->currentDamage);
	displayer.displayWaitingCoordinatesInput();
	bool attackSuccess = false;
	while (!attackSuccess) {
		try {
			params.coords = inputHandler.handleCoordsInput();
			for (int i = 0; i < params.currentDamage; i++)
			{
				if (params.field.attackCell(params.coords)) {
					user->abilityManager.addRandomAbilityCreator();
				}
			}
			params.currentDamage = 1;
			attackSuccess = true;
		}
		catch (OutOfBoundsException& e) {
			displayer.displayException(e);
			displayer.displayWaitingCoordinatesInput();
		}
	}
}



void Game::makeBotTurn() {
	Bot bot(user->field, user->shipManager);
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
}

void Game::makeTurn() {
	if (isUserTurn)
	{
		ConsoleDisplayer().displayTwoFields(user->field, bot->field);
		ConsoleDisplayer().displayAbilities(user->abilityManager);
		ConsoleDisplayer().displayAttackOrAbilityChoice();
		int choice = InputHandler().handleAttackorAbility();
		if (choice==2 ) {
			makeUserAbilityTurn();
			//wasAbilityUsed = true;
			makeUserAttackTurn();
			isUserTurn = false;
		}
		else {
			makeUserAttackTurn();
			isUserTurn = false;
		}
		ConsoleDisplayer().displayTwoFields(user->field,bot->field);
    }
	else {
		std::cout << "Bot turn\n";
		makeBotTurn();
		ConsoleDisplayer().displayTwoFields(user->field, bot->field);
		isUserTurn = true;
	}
	std::cout << "Press 'q' to quit, 's' to save game, 'l' to load game,'p' to play" << std::endl;
}

void Game::startNewGame() {
	currentRound = 1;
	user = std::make_shared<User>();
	user->abilityManager.initialiseStartCreators();
	for (int i = 0; i < user->shipManager.getShipsAmount(); i++) {
		Randomizer().placeShipRandomly(user->field, &user->shipManager.getShip(i));
	}
}


void Game::startNewRound() {
    bot->shipManager = ShipManager({ 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 });
    bot->field = GameField(10, 10);
	currentRound += 1;
}

void Game::saveGame(const std::string& filename) {
	state->save(filename);
}

void Game::loadGame(const std::string& filename) {
	auto tempUser = std::make_shared<User>();
	auto tempBot = std::make_shared<Bot>();
	GameState tempGameState(tempUser, tempBot, currentRound);

	tempGameState.load(filename);

	delete state;
	state = new GameState(tempGameState);

	user = state->getUser();
	bot = state->getBot();
}