#ifndef GAME_INPUT_CONTROLLER
#define GAME_INPUT_CONTROLLER
#include "Game.hpp"

template <class Input, class Output>

class GameInputController
{
private:
	Game& game;
	Output& output;
	Input& input;

public:
	GameInputController(Game& game, Output& output,Input& input) : game(game), output(output),input(input) {};
    bool run() {
        GameCommand gameCommand = GameCommand::HELP;
        while (gameCommand != GameCommand::QUIT) {
            switch (gameCommand) {
            case GameCommand::LOAD:
                try {
                    game.loadGame();
                }
                catch (std::exception& e) {
                    output.displayException(e);
                }
                break;
            case GameCommand::SAVE:
                try {
                    game.saveGame();
                    output.displayColoredString("Game successfully saved",32);
                }
                catch (FileOpeningException& e) {
                    output.displayException(e);
                }
                break;
            case GameCommand::ATTACK:
                this->startUserAttack();
                game.makeBotTurn();
                break;
            case GameCommand::ABILITY:
                this->startUserAbility();
                this->startUserAttack();
                game.makeBotTurn();
                break;
            case GameCommand::HELP:
                output.displayString(input.getCommandsInfo());
                break;
            default:
                output.displayColoredString("Unknown command", 31);
                break;
            }
            gameCommand = input.enterCommand();
        }
        return gameCommand == GameCommand::QUIT;
    }

    void startUserAttack() {
        bool attackSuccess = false;
        while (!attackSuccess) {
            try {
                output.displayWaitingCoordinatesInput();
                game.getUserParams().coords = input.handleCoordsInput();
                game.makeUserAttackTurn();
                attackSuccess = true;
            }
            catch (OutOfBoundsException& e) {
                output.displayException(e);
                continue;
            }
        }
    };

    void startUserAbility() {
        bool abilitySuccess = false;
        while (!abilitySuccess) {
            try {
                if (game.getState().getUser()->abilityManager.getAbilityCreator(0).getIsCoordsRequired()) {
                    output.displayWaitingCoordinatesInput();
                    game.getUserParams().coords = input.handleCoordsInput();
                }
                game.makeUserAbilityTurn();
                abilitySuccess = true;
            }
            catch (NoAbilitiesException& e) {
                output.displayException(e);
                break;
            }
            catch (OutOfBoundsException& e) {
                output.displayException(e);
                continue;
            }
        }
    }

};

#endif
