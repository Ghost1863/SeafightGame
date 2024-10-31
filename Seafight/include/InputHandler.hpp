#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include "Coordinates.hpp"
#include <iostream>

class InputHandler {
public:
	int handleAttackorAbility();
	Coordinates handleCoordsInput();
};

#endif 
