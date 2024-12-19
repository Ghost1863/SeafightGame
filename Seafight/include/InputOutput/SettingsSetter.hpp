#ifndef SETTINGS_SETTER
#define SETTINGS_SETTER
#include "InputHandler.hpp"

class SettingsSetter {
private:
	InputHandler& handler;
public:
	SettingsSetter(InputHandler& handler) : handler(handler) {};
	void setFromFile();
};
#endif 
