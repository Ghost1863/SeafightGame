#include "GameState.hpp"
#include "Game.hpp"
#include "nlohmann/json.hpp"
#include <conio.h>

int main()
{
    Game game;
    std::cout << "Press 'q' to quit, 's' to save game, 'l' to load game,'p' to play" << std::endl;
    while (true) {
        if (_kbhit()) { 
            char key = _getch(); 

            switch (key) {
            case 'q':
                std::cout << "Quitting the game." << std::endl;
                exit(0);
            case 's':
                std::cout << "Saving the game." << std::endl;
                game.saveGame("saveFile.json");
                break;
            case 'l':
                std::cout << "Loading the game." << std::endl;
                game.loadGame("saveFile.json");
                game.makeTurn();
                break;
            case 'p':
                game.makeTurn();
                game.makeTurn();
                break;
            default:
                std::cout << "Unknown command." << std::endl;
                break;
            }
        }
    }
}