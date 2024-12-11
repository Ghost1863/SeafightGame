#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include "Coordinates.hpp"
#include "GameCommand.hpp"
#include <map>
#include <sstream>
#include <iostream>

class InputHandler {
private:
	std::map<char, GameCommand> settings; 
public:

	Coordinates handleCoordsInput();
	
	InputHandler();
	void setSettings(std::map<char, GameCommand> settings);
	std::string getCommandsInfo();
	GameCommand enterCommand(const std::string message="");
};

#endif 
