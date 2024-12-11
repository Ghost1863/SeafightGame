#include "GameState.hpp"
#include "Game.hpp"
#include "nlohmann/json.hpp"
#include "GameOutputController.hpp"
#include "GameInputController.hpp"
#include "SettingsSetter.hpp"
#include <conio.h>

int main()
{
    Game game;
    ConsoleDisplayer displayer;
    InputHandler inp;

    SettingsSetter setter(inp);
    try {
        setter.setFromFile();
    }
    catch (std::exception& e) {
        displayer.displayException(e);
    }

    GameOutputController<ConsoleDisplayer>* outpControl= new GameOutputController<ConsoleDisplayer>(game.getState(), displayer);
    GameInputController<InputHandler, ConsoleDisplayer> inputControl = GameInputController<InputHandler, ConsoleDisplayer>(game, displayer, inp);
    game.addObserver(outpControl);
 
    bool end = false;
    while (!end) {
        end = inputControl.run();
        if (!end) {
            break;
        }
    }
    return 0;
}