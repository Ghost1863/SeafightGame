#ifndef GAMECOMMAND_HPP 
#define GAMECOMMAND_HPP

enum class GameCommand {
    ATTACK = 1,
    ABILITY = 2,
    LOAD = 3,
    SAVE = 4,
    QUIT = 5,
    HELP = 6
};

static std::string commandToString(GameCommand command) {
    {
        switch (command) {
        case GameCommand::ATTACK:
            return "Attack";
            break;
        case GameCommand::ABILITY:
            return "Use ability";
            break;
        case GameCommand::LOAD:
            return "Load";
            break;
        case GameCommand::SAVE:
            return "Save";
            break;
        case GameCommand::QUIT:
            return "Quit";
            break;
        case GameCommand::HELP:
            return "Help";
            break;
        default:
            return "Unknown command";
            break;
        }
    }
}

#endif 