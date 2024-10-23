#include "InputHandler.hpp"

int InputHandler::handleAttackorAbility() {
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

Coordinates InputHandler::handleCoordsInput() {
    int x, y;
    std::cin >> x >> y;
    return Coordinates{ x,y };
}