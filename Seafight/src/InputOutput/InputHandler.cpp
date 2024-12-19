#include "InputHandler.hpp"
#include <conio.h>

InputHandler::InputHandler() {
    settings = { {'1', GameCommand::ATTACK},   {'2', GameCommand::ABILITY},
               {'l', GameCommand::LOAD},      {'s', GameCommand::SAVE},
               {'h', GameCommand::HELP},      {'q', GameCommand::QUIT} };
}

Coordinates InputHandler::handleCoordsInput() {
    int x, y;
    while (true) {
        std::cin >> x >> y;

        if (std::cin.fail()) {
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем оставшиеся символы
        }
        else {
            // Если ввод корректный, игнорируем оставшиеся символы и выходим из цикла
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return Coordinates{ x, y };
}

void InputHandler::setSettings(std::map<char, GameCommand> settings) {
    this->settings = settings;
}
std::string InputHandler::getCommandsInfo() {
    std::stringstream ss;
    for (auto it = settings.begin(); it != settings.end(); ++it) {
        char key = it->first;
        GameCommand command = it->second;
        ss << key << ": " << commandToString(command) << std::endl;
    }
    return ss.str();
}
GameCommand InputHandler::enterCommand(const std::string message) {
    if (message != "") {
        std::cout << message << std::endl;
    }
    std::string line;
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (settings.find(key) != settings.end())
                return settings[key];
        }
        return GameCommand::HELP;
    }
}