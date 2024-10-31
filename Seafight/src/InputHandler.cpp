#include "InputHandler.hpp"

int InputHandler::handleAttackorAbility() {
    int choice;
    while (true) {

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем оставшиеся символы
        }
        else {
            // Если ввод корректный, игнорируем оставшиеся символы и выходим из цикла
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return choice;
}

Coordinates InputHandler::handleCoordsInput() {
    int x, y;
    std::cin >> x >> y;
    return Coordinates{ x,y };
}